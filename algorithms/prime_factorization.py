def factorize(n: int) -> list[tuple[int, int]]:
    # n >= 1; пары (простое, степень).
    if n < 1:
        raise ValueError('n must be positive')
    out = []
    p = 2
    while p * p <= n:
        if n % p == 0:
            exponent = 0
            while n % p == 0:
                n //= p
                exponent += 1
            out.append((p, exponent))
        p += 1 if p == 2 else 2
    if n > 1:
        out.append((n, 1))
    return out
