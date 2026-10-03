def articulation_points(n: int, edges: list[tuple[int, int]]) -> list[int]:
    # Неориентированный мультиграф; вершины, удаление которых увеличивает число компонент.
    graph = [[] for _ in range(n)]
    for edge_id, (u, v) in enumerate(edges):
        graph[u].append((v, edge_id))
        graph[v].append((u, edge_id))
    tin = [-1] * n
    low = [0] * n
    children = [0] * n
    answer = set()
    timer = 0
    for root in range(n):
        if tin[root] != -1:
            continue
        stack = [(root, -1, 0)]
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
                    if stack[-1][1] != -1 and low[u] >= tin[parent]:
                        answer.add(parent)
                continue
            v, edge_id = graph[u][index]
            stack[-1] = (u, parent_edge, index + 1)
            if edge_id == parent_edge:
                continue
            if tin[v] == -1:
                children[u] += 1
                stack.append((v, edge_id, 0))
            else:
                low[u] = min(low[u], tin[v])
        if children[root] > 1:
            answer.add(root)
    return sorted(answer)
