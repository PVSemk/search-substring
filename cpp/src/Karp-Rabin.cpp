#include "Karp-Rabin.hpp"

#define d 256 // d is the number of characters in alphabet



std::vector<int> searchKarpRabin(std::string txt, std::string pat, int q) // q - prime number
{
    std::vector<int> result;
    int h(1);
    unsigned long N(txt.length()), M(pat.length());
    if (!N || !M)
    {
        return result;
    }

    for (int i(0); i < M - 1; i++)
        h = d * h % q;

    int phash(0), thash(0);

    for (int i(0); i < M; i++)
    {
        phash = (d * phash + pat[i]) % q;
        thash = (d * thash + txt[i]) % q;
    }

    for (int i(0), j; i <= N - M; i++)
    {
        if (thash == phash)
        {
            for (j = 0; j < M; j++)
                if (txt[j + i] != pat[j])
                    break;

            if (j == pat.length())
            {
                result.push_back(i);
            }
        }

        if ( i < N - M ) {
            thash = (d * (thash - txt[i] * h) + txt[i + M]) % q;

            if (thash < 0)
               thash = (thash + q);

        }
    }

    return result;


}