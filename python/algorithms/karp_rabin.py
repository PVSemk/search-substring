__all__ = ['KarpRabin']
from substring_search import karp_rabin
from time import time

from .base import Results


class KarpRabin:
    def __init__(self, text, pattern):
        self.text = text
        self.pattern = pattern
        self.len_pat = len(pattern)
        self.q = self._next_prime(self.len_pat)

    def search(self):
        results = Results()
        timer = time()
        results.matches.extend(karp_rabin(self.text, self.pattern, self.q))
        results.time = time() - timer
        return results

    @staticmethod
    def _check_prime(value):
        if value in (0, 1):
            return False
        i = 2
        while i * i <= value:
            if value % i == 0:
                return False
            i += 1
        return True

    def _next_prime(self, value):
        while not self._check_prime(value):
            value += 1
        return value
