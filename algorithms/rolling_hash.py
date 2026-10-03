class RollingHash:
    # Полиномиальный хеш; hash(l, r) для [l, r). Возможны коллизии.
    def __init__(self, s: str, base: int = 911382323, mod: int = 1000000007):
        self.mod = mod
        self.power = [1] * (len(s) + 1)
        self.prefix = [0] * (len(s) + 1)
        for i, ch in enumerate(s):
            self.power[i + 1] = self.power[i] * base % mod
            self.prefix[i + 1] = (self.prefix[i] * base + ord(ch) + 1) % mod

    def hash(self, left: int, right: int) -> int:
        return (self.prefix[right] - self.prefix[left] * self.power[right - left]) % self.mod
