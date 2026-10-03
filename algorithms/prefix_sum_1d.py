class PrefixSum:
    # Сумма на [left, right).
    def __init__(self, values: list[int]):
        self.pref = [0]
        for value in values:
            self.pref.append(self.pref[-1] + value)

    def query(self, left: int, right: int) -> int:
        return self.pref[right] - self.pref[left]
