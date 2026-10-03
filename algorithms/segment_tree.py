class SegmentTree:
    # Сумма на [l, r), точечное присваивание.
    def __init__(self, values: list[int]):
        self.n = len(values)
        self.size = 1
        while self.size < self.n:
            self.size *= 2
        self.tree = [0] * (2 * self.size)
        self.tree[self.size:self.size + self.n] = values
        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]

    def set(self, index: int, value: int) -> None:
        i = self.size + index
        self.tree[i] = value
        while i > 1:
            i //= 2
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]

    def query(self, left: int, right: int) -> int:
        left += self.size
        right += self.size
        answer = 0
        while left < right:
            if left & 1:
                answer += self.tree[left]
                left += 1
            if right & 1:
                right -= 1
                answer += self.tree[right]
            left //= 2
            right //= 2
        return answer
