def count_pairs_sum_leq(sorted_values: list[int], limit: int) -> int:
    # Массив должен быть отсортирован; пары i < j.
    left, right = 0, len(sorted_values) - 1
    answer = 0
    while left < right:
        if sorted_values[left] + sorted_values[right] <= limit:
            answer += right - left
            left += 1
        else:
            right -= 1
    return answer
