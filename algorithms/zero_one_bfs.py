from collections import deque


def zero_one_bfs(graph: list[list[tuple[int, int]]], source: int) -> list[int]:
    # Ребра (v, weight), weight равен 0 или 1; недостижимое = 10**30.
    inf = 10**30
    dist = [inf] * len(graph)
    dist[source] = 0
    queue = deque([source])
    while queue:
        u = queue.popleft()
        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                if weight == 0:
                    queue.appendleft(v)
                else:
                    queue.append(v)
    return dist
