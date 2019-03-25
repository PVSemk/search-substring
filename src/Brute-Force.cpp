//
// Created by pavel on 25.03.19.
//
#include "Brute-Force.h"

std::vector<int> bruteForceSearch(std::string txt, std::string pat)
{
    std::vector<int> result;
    // Check all possible shifts
    for (int i(0); i <= txt.length() - pat.length(); i++)
    {
        int j(i);
        // Check equality of txt[i...i + pat.length - 1] and template
        for (int k(0); j < i + pat.length(); j++, k++)
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