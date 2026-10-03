def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return abs(a)


def lcm(a: int, b: int) -> int:
    return 0 if a == 0 or b == 0 else abs(a // gcd(a, b) * b)
