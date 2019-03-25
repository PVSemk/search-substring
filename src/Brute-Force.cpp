//
// Created by pavel on 25.03.19.
//
#include "Brute-Force.h"

std::vector<int> bruteForceSearch(std::string s, std::string t)
{
    std::vector<int> result;
    // Check all possible shifts
    for (int i(0); i <= s.length() - t.length(); i++)
    {
        int j(i);
        // Check equality of s[i...i + t.length - 1] and template
        for (int k(0); j < i + t.length(); j++, k++)
            if (s[j] != t[k])
                break;
        // Add a current shift into the result if all the symbols are equal
        if (j - i == t.length())
        {
            result.push_back(i);
        }
    }
    return result;
}