class PrefixSum2D:
    # Сумма прямоугольника [r1, r2) x [c1, c2).
    def __init__(self, grid: list[list[int]]):
        rows = len(grid)
        cols = len(grid[0]) if rows else 0
        self.pref = [[0] * (cols + 1) for _ in range(rows + 1)]
        for r in range(rows):
            for c in range(cols):
                self.pref[r + 1][c + 1] = grid[r][c] + self.pref[r][c + 1] + self.pref[r + 1][c] - self.pref[r][c]

    def query(self, r1: int, c1: int, r2: int, c2: int) -> int:
        p = self.pref
        return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1]
