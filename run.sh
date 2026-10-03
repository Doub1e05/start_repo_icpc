#!/usr/bin/env bash
set -euo pipefail
if [[ $# -lt 1 || ! -f $1 ]]; then
  echo 'Usage: ./run.sh A.py|A.cpp [cases/A.toml [--timeout SECONDS]]' >&2
  exit 2
fi
script_dir=$(cd -- "$(dirname -- "$0")" && pwd)
if [[ $# -ge 2 ]]; then
  exec python3 "$script_dir/case_runner.py" "$@"
fi
case "$1" in
  *.py) exec python3 "$1" ;;
  *.cpp)
    tmp_dir=$(mktemp -d)
    trap 'rm -rf "$tmp_dir"' EXIT
    g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -I "$script_dir/local_include" -o "$tmp_dir/solution" "$1"
    "$tmp_dir/solution"
    ;;
  *) echo 'Expected .py or .cpp' >&2; exit 2 ;;
esac
