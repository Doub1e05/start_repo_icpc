def floyd_warshall(dist: list[list[int]], inf: int = 10**30) -> list[list[int]]:
    # Матрица весов: dist[i][i]=0, отсутствующее ребро=inf.
    n = len(dist)
    d = [row[:] for row in dist]
    for k in range(n):
        for i in range(n):
            if d[i][k] == inf:
                continue
            for j in range(n):
                if d[k][j] != inf and d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]
    return d
