def crt_pair(a: int, m: int, b: int, n: int) -> tuple[int, int] | None:
    # x=a (mod m), x=b (mod n); m,n > 0. None, если нет решения.
    def extended_gcd(x, y):
        if y == 0:
            return x, 1, 0
        g, p, q = extended_gcd(y, x % y)
        return g, q, p - (x // y) * q

    g, inverse, _ = extended_gcd(m, n)
    if (b - a) % g:
        return None
    modulus = m // g * n
    step = ((b - a) // g * inverse) % (n // g)
    return (a + m * step) % modulus, modulus
