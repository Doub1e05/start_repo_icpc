def bridges(n: int, edges: list[tuple[int, int]]) -> list[int]:
    # Неориентированный мультиграф; возвращает индексы ребер-мостов.
    graph = [[] for _ in range(n)]
    for edge_id, (u, v) in enumerate(edges):
        graph[u].append((v, edge_id))
        graph[v].append((u, edge_id))
    tin = [-1] * n
    low = [0] * n
    timer = 0
    answer = []
    for start in range(n):
        if tin[start] != -1:
            continue
        stack = [(start, -1, 0)]
        while stack:
            u, parent_edge, index = stack[-1]
            if tin[u] == -1:
                tin[u] = low[u] = timer
                timer += 1
            if index == len(graph[u]):
                stack.pop()
                if stack:
                    parent = stack[-1][0]
                    low[parent] = min(low[parent], low[u])
                    if low[u] > tin[parent]:
                        answer.append(parent_edge)
                continue
            v, edge_id = graph[u][index]
            stack[-1] = (u, parent_edge, index + 1)
            if edge_id == parent_edge:
                continue
            if tin[v] == -1:
                stack.append((v, edge_id, 0))
            else:
                low[u] = min(low[u], tin[v])
    return answer
