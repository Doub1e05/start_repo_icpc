def compress(values: list[int]) -> tuple[list[int], list[int]]:
    # Возвращает индексы элементов и отсортированный список уникальных значений.
    unique = sorted(set(values))
    rank = {value: i for i, value in enumerate(unique)}
    return [rank[value] for value in values], unique
