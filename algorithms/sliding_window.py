def longest_subarray_sum_leq_nonnegative(a: list[int], limit: int) -> int:
    # Только для a[i] >= 0.
    left = total = answer = 0
    for right, value in enumerate(a):
        total += value
        while left <= right and total > limit:
            total -= a[left]
            left += 1
        answer = max(answer, right - left + 1)
    return answer
