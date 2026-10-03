def bellman_ford(n: int, edges: list[tuple[int, int, int]], source: int) -> tuple[list[int], bool]:
    # Ориентированные (u, v, w). bool=True, если достижим отрицательный цикл.
    inf = 10**30
    dist = [inf] * n
    dist[source] = 0
    for _ in range(n - 1):
        changed = False
        for u, v, weight in edges:
            if dist[u] != inf and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                changed = True
        if not changed:
            break
    negative_cycle = any(dist[u] != inf and dist[u] + w < dist[v] for u, v, w in edges)
    return dist, negative_cycle
