from collections import deque


def bfs(graph: list[list[int]], source: int) -> list[int]:
    # Невозможное расстояние = -1.
    dist = [-1] * len(graph)
    dist[source] = 0
    queue = deque([source])
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                queue.append(v)
    return dist
