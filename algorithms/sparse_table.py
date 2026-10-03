class SparseTableMin:
    # Статический минимум на непустом [l, r).
    def __init__(self, values: list[int]):
        if not values:
            raise ValueError('values must be nonempty')
        self.table = [values[:]]
        step = 1
        while 2 * step <= len(values):
            prev = self.table[-1]
            self.table.append([min(prev[i], prev[i + step]) for i in range(len(values) - 2 * step + 1)])
            step *= 2

    def query(self, left: int, right: int) -> int:
        k = (right - left).bit_length() - 1
        return min(self.table[k][left], self.table[k][right - (1 << k)])
