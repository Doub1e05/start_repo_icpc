class LCA:
    # Неориентированное дерево; root по умолчанию 0.
    def __init__(self, graph: list[list[int]], root: int = 0):
        n = len(graph)
        self.depth = [-1] * n
        self.depth[root] = 0
        levels = max(1, n.bit_length())
        self.up = [[root] * n for _ in range(levels)]
        stack = [root]
        while stack:
            u = stack.pop()
            for v in graph[u]:
                if self.depth[v] == -1:
                    self.depth[v] = self.depth[u] + 1
                    self.up[0][v] = u
                    stack.append(v)
        for k in range(1, levels):
            for v in range(n):
                self.up[k][v] = self.up[k - 1][self.up[k - 1][v]]

    def query(self, a: int, b: int) -> int:
        if self.depth[a] < self.depth[b]:
            a, b = b, a
        difference = self.depth[a] - self.depth[b]
        for k in range(len(self.up)):
            if difference >> k & 1:
                a = self.up[k][a]
        if a == b:
            return a
        for k in range(len(self.up) - 1, -1, -1):
            if self.up[k][a] != self.up[k][b]:
                a, b = self.up[k][a], self.up[k][b]
        return self.up[0][a]
