#include "Knuth-Morris-Pratt.hpp"

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

std::vector<int> searchKMP(std::string txt, std::string pat) {
    unsigned long N(txt.length()), M(pat.length());
    std::vector<int> result;
    if (!N || !M)
    {
        return result;
    }
    std::vector<int> pref = computePrefixFunction(pat);

    int tail(-1);
    for (int i(0); i < N; i++)
    {
        while (tail > -1 && pat[tail + 1] != txt[i])
            tail = pref[tail];
        if (pat[tail + 1] == txt[i])
            tail++;
        if (tail == M - 1)
        {
            result.push_back(i - tail);
            tail = pref[tail];
        }
    }
    return result;
}
