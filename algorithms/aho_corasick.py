from collections import deque


def aho_count(text: str, patterns: list[str]) -> list[int]:
    # Строчные латинские буквы; все patterns непустые. Число вхождений каждого.
    next_node = [[-1] * 26]
    terminal = []
    for pattern in patterns:
        u = 0
        for ch in pattern:
            c = ord(ch) - 97
            if next_node[u][c] == -1:
                next_node[u][c] = len(next_node)
                next_node.append([-1] * 26)
            u = next_node[u][c]
        terminal.append(u)
    link = [0] * len(next_node)
    order = []
    queue = deque()
    for c in range(26):
        v = next_node[0][c]
        if v == -1:
            next_node[0][c] = 0
        else:
            queue.append(v)
    while queue:
        u = queue.popleft()
        order.append(u)
        for c in range(26):
            v = next_node[u][c]
            if v == -1:
                next_node[u][c] = next_node[link[u]][c]
            else:
                link[v] = next_node[link[u]][c]
                queue.append(v)
    count = [0] * len(next_node)
    u = 0
    for ch in text:
        u = next_node[u][ord(ch) - 97]
        count[u] += 1
    for u in reversed(order):
        count[link[u]] += count[u]
    return [count[u] for u in terminal]
