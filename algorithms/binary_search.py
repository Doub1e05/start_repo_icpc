def first_true(lo: int, hi: int, predicate) -> int:
    # [lo, hi): False ... False, True ... True; вернет hi, если True нет.
    while lo < hi:
        mid = (lo + hi) // 2
        if predicate(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo
