#!/usr/bin/env python3
"""Run each TOML test case in a fresh process; compile C++ only once."""

import argparse
import subprocess
import sys
import tempfile
import tomllib
from pathlib import Path


def load_cases(path: Path) -> list[dict[str, str]]:
    try:
        with path.open("rb") as file:
            document = tomllib.load(file)
    except (OSError, tomllib.TOMLDecodeError) as error:
        raise ValueError(f"Не удалось прочитать {path}: {error}") from error
    cases = document.get("case")
    if not isinstance(cases, list) or not cases:
        raise ValueError(f"В {path} нет кейсов [[case]]")
    for number, case in enumerate(cases, 1):
        if not isinstance(case, dict) or not isinstance(case.get("input"), str):
            raise ValueError(f"Кейс {number}: нужно строковое поле input")
        for field in ("name", "expected"):
            if field in case and not isinstance(case[field], str):
                raise ValueError(f"Кейс {number}: поле {field} должно быть строкой")
    return cases


def show_output(value: str) -> None:
    if value:
        print(value.rstrip("\n"))
    else:
        print("(пустой вывод)")


def run_cases(command: list[str], cases: list[dict[str, str]], timeout: float) -> bool:
    passed = failed = unchecked = 0
    for number, case in enumerate(cases, 1):
        name = case.get("name", f"кейс {number}")
        try:
            result = subprocess.run(
                command,
                input=case["input"],
                text=True,
                capture_output=True,
                timeout=timeout,
            )
        except subprocess.TimeoutExpired:
            failed += 1
            print(f"[{number}] {name}: TIMEOUT (>{timeout:g} с)")
            continue
        if result.returncode != 0:
            failed += 1
            print(f"[{number}] {name}: ОШИБКА ВЫПОЛНЕНИЯ (код {result.returncode})")
            if result.stderr:
                print(result.stderr.rstrip())
            continue
        if "expected" not in case:
            unchecked += 1
            print(f"[{number}] {name}: вывод")
            show_output(result.stdout)
            continue
        # Типичные ICPC-проверки игнорируют различия пробельных символов.
        if result.stdout.split() == case["expected"].split():
            passed += 1
            print(f"[{number}] {name}: УСПЕШНО")
        else:
            failed += 1
            print(f"[{number}] {name}: НЕ ПРОШЁЛ")
            print("  Ожидалось:")
            show_output(case["expected"])
            print("  Получено:")
            show_output(result.stdout)
    print(f"Итого: успешно {passed}, не прошли {failed}, без ожидаемого ответа {unchecked}")
    return failed == 0


def main() -> int:
    parser = argparse.ArgumentParser(description="Запуск нескольких ICPC-кейсов")
    parser.add_argument("source", type=Path, help="файл задачи .py или .cpp")
    parser.add_argument("cases", type=Path, help="TOML-файл с [[case]]")
    parser.add_argument("--timeout", type=float, default=3.0, help="секунд на один кейс (по умолчанию 3)")
    args = parser.parse_args()
    if not args.source.is_file() or args.source.suffix not in (".py", ".cpp"):
        parser.error("source должен быть существующим .py или .cpp файлом")
    if args.timeout <= 0:
        parser.error("--timeout должен быть положительным")
    try:
        cases = load_cases(args.cases)
    except ValueError as error:
        parser.error(str(error))

    if args.source.suffix == ".py":
        return 0 if run_cases([sys.executable, str(args.source.resolve())], cases, args.timeout) else 1

    with tempfile.TemporaryDirectory(prefix="icpc-") as temporary:
        executable = Path(temporary) / "solution"
        local_include = Path(__file__).resolve().parent / "local_include"
        compile_result = subprocess.run(
            ["g++", "-std=c++17", "-O2", "-Wall", "-Wextra", "-Wshadow", "-I", str(local_include), "-o", str(executable), str(args.source)],
            text=True,
            capture_output=True,
        )
        if compile_result.returncode != 0:
            print("Ошибка компиляции:", file=sys.stderr)
            print(compile_result.stderr, file=sys.stderr, end="")
            return 1
        return 0 if run_cases([str(executable)], cases, args.timeout) else 1


if __name__ == "__main__":
    raise SystemExit(main())
