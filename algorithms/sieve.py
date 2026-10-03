def sieve(n: int) -> list[int]:
    # Все простые p <= n.
    if n < 2:
        return []
    prime = bytearray(b'\x01') * (n + 1)
    prime[0:2] = b'\x00\x00'
    for p in range(2, int(n ** 0.5) + 1):
        if prime[p]:
            prime[p * p:n + 1:p] = b'\x00' * ((n - p * p) // p + 1)
    return [i for i in range(n + 1) if prime[i]]
