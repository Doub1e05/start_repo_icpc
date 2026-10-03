from collections import deque


class Dinic:
    # add_edge(u, v, capacity) — ориентированное ребро.
    def __init__(self, n: int):
        self.graph = [[] for _ in range(n)]

    def add_edge(self, u: int, v: int, capacity: int) -> None:
        forward = [v, capacity, len(self.graph[v]) + (u == v)]
        backward = [u, 0, len(self.graph[u])]
        self.graph[u].append(forward)
        self.graph[v].append(backward)

    def max_flow(self, source: int, sink: int) -> int:
        if source == sink:
            return 0
        n = len(self.graph)
        result = 0
        while True:
            level = [-1] * n
            level[source] = 0
            queue = deque([source])
            while queue:
                u = queue.popleft()
                for v, capacity, _ in self.graph[u]:
                    if capacity > 0 and level[v] == -1:
                        level[v] = level[u] + 1
                        queue.append(v)
            if level[sink] == -1:
                return result
            ptr = [0] * n

            def send(u: int, pushed: int) -> int:
                if u == sink:
                    return pushed
                while ptr[u] < len(self.graph[u]):
                    edge = self.graph[u][ptr[u]]
                    v, capacity, reverse = edge
                    if capacity > 0 and level[v] == level[u] + 1:
                        sent = send(v, min(pushed, capacity))
                        if sent:
                            edge[1] -= sent
                            self.graph[v][reverse][1] += sent
                            return sent
                    ptr[u] += 1
                return 0

            while pushed := send(source, 10**30):
                result += pushed
