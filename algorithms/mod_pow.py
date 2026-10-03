def mod_pow(a: int, exp: int, mod: int) -> int:
    if exp < 0 or mod <= 0:
        raise ValueError('need exp >= 0 and mod > 0')
    result = 1 % mod
    a %= mod
    while exp:
        if exp & 1:
            result = result * a % mod
        a = a * a % mod
        exp >>= 1
    return result
