from bisect import bisect_left


def lis_length(values: list[int]) -> int:
    # Строго возрастающая подпоследовательность.
    tails = []
    for value in values:
        index = bisect_left(tails, value)
        if index == len(tails):
            tails.append(value)
        else:
            tails[index] = value
    return len(tails)
