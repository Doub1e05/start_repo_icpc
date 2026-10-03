def matrix_power(matrix: list[list[int]], exponent: int, mod: int) -> list[list[int]]:
    # Квадратная матрица; exponent >= 0.
    n = len(matrix)

    def multiply(a, b):
        result = [[0] * n for _ in range(n)]
        for i in range(n):
            for k in range(n):
                if a[i][k]:
                    for j in range(n):
                        result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod
        return result

    result = [[int(i == j) for j in range(n)] for i in range(n)]
    while exponent:
        if exponent & 1:
            result = multiply(result, matrix)
        matrix = multiply(matrix, matrix)
        exponent >>= 1
    return result
