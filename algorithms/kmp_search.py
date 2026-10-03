def kmp_search(text: str, pattern: str) -> list[int]:
    # Все позиции вхождений; пустой pattern совпадает на каждой границе.
    if not pattern:
        return list(range(len(text) + 1))
    pi = [0] * len(pattern)
    for i in range(1, len(pattern)):
        j = pi[i - 1]
        while j and pattern[i] != pattern[j]:
            j = pi[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        pi[i] = j
    answer = []
    j = 0
    for i, ch in enumerate(text):
        while j and ch != pattern[j]:
            j = pi[j - 1]
        if ch == pattern[j]:
            j += 1
        if j == len(pattern):
            answer.append(i - j + 1)
            j = pi[j - 1]
    return answer
