def apply_range_add(values: list[int], updates: list[tuple[int, int, int]]) -> list[int]:
    # Каждое обновление (left, right, delta) на [left, right).
    n = len(values)
    diff = [0] * (n + 1)
    for left, right, delta in updates:
        diff[left] += delta
        diff[right] -= delta
    result = values[:]
    running = 0
    for i in range(n):
        running += diff[i]
        result[i] += running
    return result
