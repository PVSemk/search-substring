__all__ = ['BruteForce']
from time import time
from substring_search import brute_force
from .base import Results


class BruteForce:
    def __init__(self, text, pattern):
        self.text = text
        self.pattern = pattern

    def search(self):
        results = Results()
        timer = time()
        results.matches.extend(brute_force(self.text, self.pattern))
        results.time = time() - timer
        return results
