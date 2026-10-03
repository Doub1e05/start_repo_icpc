from collections import deque


def topological_sort(graph: list[list[int]]) -> list[int]:
    # Ориентированный граф; при цикле возвращает [].
    n = len(graph)
    indegree = [0] * n
    for adj in graph:
        for v in adj:
            indegree[v] += 1
    queue = deque(i for i in range(n) if indegree[i] == 0)
    order = []
    while queue:
        u = queue.popleft()
        order.append(u)
        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)
    return order if len(order) == n else []
