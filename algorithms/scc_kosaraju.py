def strongly_connected_components(graph: list[list[int]]) -> list[list[int]]:
    # Ориентированный граф; компоненты сильной связности.
    n = len(graph)
    reverse = [[] for _ in range(n)]
    for u in range(n):
        for v in graph[u]:
            reverse[v].append(u)
    seen = [False] * n
    order = []
    for start in range(n):
        if seen[start]:
            continue
        seen[start] = True
        stack = [(start, 0)]
        while stack:
            u, index = stack[-1]
            if index == len(graph[u]):
                order.append(u)
                stack.pop()
            else:
                v = graph[u][index]
                stack[-1] = (u, index + 1)
                if not seen[v]:
                    seen[v] = True
                    stack.append((v, 0))
    seen = [False] * n
    components = []
    for start in reversed(order):
        if seen[start]:
            continue
        component = []
        stack = [start]
        seen[start] = True
        while stack:
            u = stack.pop()
            component.append(u)
            for v in reverse[u]:
                if not seen[v]:
                    seen[v] = True
                    stack.append(v)
        components.append(component)
    return components
