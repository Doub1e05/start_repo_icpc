def segments_intersect(a: tuple[int, int], b: tuple[int, int],
                       c: tuple[int, int], d: tuple[int, int]) -> bool:
    # Пересечение замкнутых отрезков; касание считается.
    def cross(p, q, r):
        return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0])

    def on_segment(p, q, r):
        return min(p[0], q[0]) <= r[0] <= max(p[0], q[0]) and min(p[1], q[1]) <= r[1] <= max(p[1], q[1])

    x1, x2 = cross(a, b, c), cross(a, b, d)
    y1, y2 = cross(c, d, a), cross(c, d, b)
    if x1 == 0 and on_segment(a, b, c) or x2 == 0 and on_segment(a, b, d):
        return True
    if y1 == 0 and on_segment(c, d, a) or y2 == 0 and on_segment(c, d, b):
        return True
    return (x1 < 0 < x2 or x2 < 0 < x1) and (y1 < 0 < y2 or y2 < 0 < y1)
