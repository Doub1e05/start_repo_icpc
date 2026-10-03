class Fenwick:
    # Индексы с нуля; sum_range(l, r) считает [l, r).
    def __init__(self, n: int):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, index: int, delta: int) -> None:
        index += 1
        while index <= self.n:
            self.bit[index] += delta
            index += index & -index

    def prefix_sum(self, end: int) -> int:
        result = 0
        while end:
            result += self.bit[end]
            end -= end & -end
        return result

    def sum_range(self, left: int, right: int) -> int:
        return self.prefix_sum(right) - self.prefix_sum(left)
