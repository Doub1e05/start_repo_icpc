from functools import lru_cache


def count_without_adjacent_equal(n: int) -> int:
    # Количество целых x в [0, n] без одинаковых соседних цифр.
    if n < 0:
        return 0
    digits = str(n)

    @lru_cache(None)
    def dp(pos: int, previous: int, tight: bool, started: bool) -> int:
        if pos == len(digits):
            return 1
        total = 0
        upper = int(digits[pos]) if tight else 9
        for digit in range(upper + 1):
            next_started = started or digit != 0
            if started and digit == previous:
                continue
            total += dp(pos + 1, digit if next_started else 10,
                        tight and digit == upper, next_started)
        return total

    return dp(0, 10, True, False)
