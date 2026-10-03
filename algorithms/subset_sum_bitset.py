def subset_sum_possible(values: list[int], target: int) -> bool:
    # values >= 0; Python big-int как битсет.
    bits = 1
    for value in values:
        bits |= bits << value
    return bool(bits >> target & 1)
