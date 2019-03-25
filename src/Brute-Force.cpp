//
// Created by pavel on 25.03.19.
//
#include "Brute-Force.h"

std::vector<int> bruteForceSearch(std::string s, std::string t)
{
    std::vector<int> result;
    for (int i(0); i <= s.length() - t.length(); i++)
    {
        int j(i);
        for (int k(0); j < i + t.length(); j++, k++)
            if (s[j] != t[k])
                break;
        if (j - i == t.length())
        {
            result.push_back(i);
        }
    }
    return result;
}