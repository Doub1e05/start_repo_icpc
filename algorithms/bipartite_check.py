from collections import deque


def bipartite_coloring(graph: list[list[int]]) -> list[int]:
    # Неориентированный граф; цвета 0/1 или [] при не двудольности.
    color = [-1] * len(graph)
    for start in range(len(graph)):
        if color[start] != -1:
            continue
        color[start] = 0
        queue = deque([start])
        while queue:
            u = queue.popleft()
            for v in graph[u]:
                if color[v] == -1:
                    color[v] = color[u] ^ 1
                    queue.append(v)
                elif color[v] == color[u]:
                    return []
    return color
