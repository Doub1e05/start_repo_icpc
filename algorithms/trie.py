class Trie:
    # Строки только из строчных латинских букв.
    def __init__(self):
        self.next = [{}]
        self.terminal = [False]

    def insert(self, word: str) -> None:
        node = 0
        for ch in word:
            if ch not in self.next[node]:
                self.next[node][ch] = len(self.next)
                self.next.append({})
                self.terminal.append(False)
            node = self.next[node][ch]
        self.terminal[node] = True

    def contains(self, word: str) -> bool:
        node = 0
        for ch in word:
            if ch not in self.next[node]:
                return False
            node = self.next[node][ch]
        return self.terminal[node]
