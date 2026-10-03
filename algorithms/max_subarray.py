def max_subarray_sum(values: list[int]) -> int:
    # Непустой подмассив; values должен быть непустым.
    best = current = values[0]
    for value in values[1:]:
        current = max(value, current + value)
        best = max(best, current)
    return best
