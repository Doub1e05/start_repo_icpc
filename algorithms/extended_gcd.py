def extended_gcd(a: int, b: int) -> tuple[int, int, int]:
    # g = a*x + b*y, g >= 0
    old_r, r = a, b
    old_x, x = 1, 0
    old_y, y = 0, 1
    while r:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_x, x = x, old_x - q * x
        old_y, y = y, old_y - q * y
    if old_r < 0:
        return -old_r, -old_x, -old_y
    return old_r, old_x, old_y


def mod_inverse(a: int, mod: int) -> int:
    g, x, _ = extended_gcd(a, mod)
    if g != 1:
        raise ValueError('inverse does not exist')
    return x % mod
