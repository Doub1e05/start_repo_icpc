def dfs_order(graph: list[list[int]], source: int) -> list[int]:
    # Итеративный DFS, порядок первого посещения.
    seen = [False] * len(graph)
    order = []
    stack = [source]
    while stack:
        u = stack.pop()
        if seen[u]:
            continue
        seen[u] = True
        order.append(u)
        stack.extend(reversed(graph[u]))
    return order
