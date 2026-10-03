class LazySegmentTree:
    # Прибавить delta на [l, r), узнать сумму [l, r).
    def __init__(self, values: list[int]):
        self.n = len(values)
        self.tree = [0] * (4 * max(1, self.n))
        self.lazy = [0] * len(self.tree)

        def build(node: int, left: int, right: int) -> None:
            if right - left == 1:
                self.tree[node] = values[left]
                return
            mid = (left + right) // 2
            build(2 * node, left, mid)
            build(2 * node + 1, mid, right)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

        if self.n:
            build(1, 0, self.n)

    def _apply(self, node: int, length: int, delta: int) -> None:
        self.tree[node] += delta * length
        self.lazy[node] += delta

    def _push(self, node: int, left: int, right: int) -> None:
        if self.lazy[node] and right - left > 1:
            mid = (left + right) // 2
            self._apply(2 * node, mid - left, self.lazy[node])
            self._apply(2 * node + 1, right - mid, self.lazy[node])
            self.lazy[node] = 0

    def add(self, ql: int, qr: int, delta: int) -> None:
        def visit(node: int, left: int, right: int) -> None:
            if qr <= left or right <= ql:
                return
            if ql <= left and right <= qr:
                self._apply(node, right - left, delta)
                return
            self._push(node, left, right)
            mid = (left + right) // 2
            visit(2 * node, left, mid)
            visit(2 * node + 1, mid, right)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

        if self.n:
            visit(1, 0, self.n)

    def query(self, ql: int, qr: int) -> int:
        def visit(node: int, left: int, right: int) -> int:
            if qr <= left or right <= ql:
                return 0
            if ql <= left and right <= qr:
                return self.tree[node]
            self._push(node, left, right)
            mid = (left + right) // 2
            return visit(2 * node, left, mid) + visit(2 * node + 1, mid, right)

        return visit(1, 0, self.n) if self.n else 0
