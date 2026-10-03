from heapq import heappop, heappush


def dijkstra(graph: list[list[tuple[int, int]]], source: int) -> list[int]:
    # Ребра (v, weight), weight >= 0. Недостижимое = 10**30.
    inf = 10**30
    dist = [inf] * len(graph)
    dist[source] = 0
    heap = [(0, source)]
    while heap:
        current, u = heappop(heap)
        if current != dist[u]:
            continue
        for v, weight in graph[u]:
            candidate = current + weight
            if candidate < dist[v]:
                dist[v] = candidate
                heappush(heap, (candidate, v))
    return dist
