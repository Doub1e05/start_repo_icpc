def tsp_cycle(cost: list[list[int]]) -> int:
    # Начало и конец в 0; полная матрица весов, n >= 1.
    n = len(cost)
    inf = 10**30
    dp = [[inf] * n for _ in range(1 << n)]
    dp[1][0] = 0
    for mask in range(1, 1 << n):
        for u in range(n):
            if dp[mask][u] == inf:
                continue
            for v in range(n):
                if not (mask >> v & 1):
                    next_mask = mask | (1 << v)
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + cost[u][v])
    return min(dp[-1][u] + cost[u][0] for u in range(n))
