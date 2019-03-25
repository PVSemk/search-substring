//
// Created by pavel on 25.03.19.
//
#include "Knuth-Morris-Pratt.h"

// The prefix function for a pattern encapsulates knowledge about how the
// pattern matches against shifts of itself
std::vector<int> computePrefixFunction(std::string pat)
{
    unsigned long M(pat.length());
    std::vector<int> res(M, -1);
    int k(-1);
    for (int i(1); i < M; i++)
    {
        while (k > -1 && pat[k+1] != pat[i])
            k = res[k];
        if (pat[k+1] == pat[i])
            res[i] = ++k;
    }
    return res;
}

std::vector<int> searchKMP(std::string txt, std::string pat)
{
    unsigned long N(txt.length()), M(pat.length());
    std::vector<int> pref = computePrefixFunction(pat);
    std::vector<int> result;
    int tail(-1);
    for (int i(0); i < N; i++) // Scan text from left to right
    {
        while (tail > -1 && pat[tail + 1] != txt[i])
            tail = pref[tail]; // Next symbol doesn't match
        if (pat[tail + 1] == txt[i])
            tail++; // Next symbol matches
        if (tail == M - 1) // Check if all symbols match
        {
            result.push_back(i - tail);
            tail = pref[tail]; // Search for the next matching
        }
    }
    return result;
}
