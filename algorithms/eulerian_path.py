def directed_eulerian_path(n: int, edges: list[tuple[int, int]]) -> list[int]:
    # Ориентированный мультиграф; путь из всех ребер или [].
    if n == 0:
        return []
    graph = [[] for _ in range(n)]
    indegree = [0] * n
    outdegree = [0] * n
    for u, v in edges:
        graph[u].append(v)
        outdegree[u] += 1
        indegree[v] += 1
    starts = [i for i in range(n) if outdegree[i] - indegree[i] == 1]
    ends = [i for i in range(n) if indegree[i] - outdegree[i] == 1]
    if len(starts) != len(ends) or len(starts) > 1:
        return []
    if any(abs(outdegree[i] - indegree[i]) > 1 for i in range(n)):
        return []
    start = starts[0] if starts else next((i for i in range(n) if outdegree[i]), 0)
    stack = [start]
    path = []
    while stack:
        u = stack[-1]
        if graph[u]:
            stack.append(graph[u].pop())
        else:
            path.append(stack.pop())
    path.reverse()
    return path if len(path) == len(edges) + 1 else []
