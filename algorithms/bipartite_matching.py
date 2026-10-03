def bipartite_matching(graph: list[list[int]], right_size: int) -> list[tuple[int, int]]:
    # graph[left] = список правых вершин; алгоритм Куна.
    match_right = [-1] * right_size

    def augment(start: int) -> bool:
        seen = [False] * len(graph)
        stack = [(start, 0)]
        parent = {}
        seen[start] = True
        while stack:
            u, index = stack[-1]
            if index == len(graph[u]):
                stack.pop()
                continue
            v = graph[u][index]
            stack[-1] = (u, index + 1)
            matched = match_right[v]
            if matched == -1:
                while True:
                    match_right[v] = u
                    if u == start:
                        return True
                    u, v = parent[u]
            elif not seen[matched]:
                seen[matched] = True
                parent[matched] = (u, v)
                stack.append((matched, 0))
        return False

    for left in range(len(graph)):
        augment(left)
    return [(left, right) for right, left in enumerate(match_right) if left != -1]
