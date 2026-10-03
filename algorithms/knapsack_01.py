def knapsack_01(items: list[tuple[int, int]], capacity: int) -> int:
    # (weight, value), каждый предмет не более одного раза; weight >= 0.
    dp = [0] * (capacity + 1)
    for weight, value in items:
        for c in range(capacity, weight - 1, -1):
            dp[c] = max(dp[c], dp[c - weight] + value)
    return dp[capacity]
