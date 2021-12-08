//
// Created by pavel on 25.03.19.
//
#include "Brute-Force.hpp"


std::vector<int> bruteForceSearch(std::string txt, std::string pat)
{
    std::vector<int> result;
    unsigned long N(txt.length()), M(pat.length());
    // Check all possible shifts
    for (int i(0); i <= N - M; i++)
    {
        int j(i);
        // Check equality of txt[i...i + pat.length - 1] and template
        for (int k(0); j < i + M; j++, k++)
            if (txt[j] != pat[k])
                break;

        // Add a current shift into the result only if all the symbols are equal
        if (j - i == pat.length())
        {
            result.push_back(i);
        }
    }
    return result;
}