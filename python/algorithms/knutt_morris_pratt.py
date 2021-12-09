__all__ = ['KnuttMorrisPratt']
from time import time
from substring_search import knuth_morris_pratt

from .base import Results


class KnuttMorrisPratt:
    def __init__(self, text, pattern):
        self.text = text
        self.pattern = pattern

    def search(self):
        results = Results()
        timer = time()
        results.matches.extend(knuth_morris_pratt(self.text, self.pattern))
        results.time = time() - timer
        return results
