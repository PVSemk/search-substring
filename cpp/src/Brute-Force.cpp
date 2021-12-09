#include "Brute-Force.hpp"


std::vector<int> bruteForceSearch(std::string txt, std::string pat)
{
    std::vector<int> result;
    unsigned long N(txt.length()), M(pat.length());
    if (!N || !M)
    {
        return result;
    }
    for (int i(0); i <= N - M; i++)
    {
        int j(i);

        for (int k(0); j < i + M; j++, k++)
            if (txt[j] != pat[k])
                break;


        if (j - i == pat.length())
        {
            result.push_back(i);
        }
    }
    return result;
}