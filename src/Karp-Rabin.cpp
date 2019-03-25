//
// Created by pavel on 25.03.19.
//
#include "Karp-Rabin.h"

#define d 256 // d is the number of characters in alphabet



std::vector<int> searchKarpRabin(std::string txt, std::string pat, int q) // q - prime number
{
    std::vector<int> result;
    int h(1);
    unsigned long N(txt.length()), M(pat.length());

    // Count h variable in order to recount hash later
    // (It will help to remove the leading symbol)
    // Formula: h = pow(d, M - 1) % q
    for (int i(0); i < M - 1; i++)
        h = d * h % q;

    int phash(0), thash(0); // hash value for the pattern and text

    // Calculate value for the pattern and the first window of the string
    for (int i(0); i < M; i++)
    {
        phash = (d * phash + pat[i]) % q;
        thash = (d * thash + txt[i]) % q;
    }

    // Check all possible shifts
    for (int i(0), j; i <= N - M; i++)
    {
        // Check hash values of the current window and the pattern
        // If they are equal, compare all symbols in order to exclude collision-cases
        if (thash == phash)
        {
            // Check equality of txt[i...i + pat.length - 1] and pattern
            for (j = 0; j < M; j++)
                if (txt[j + i] != pat[j])
                    break;

            // Add a current shift into the result only if all the symbols are equal
            if (j == pat.length())
            {
                result.push_back(i);
            }
        }
        // Calculate hash value for next window of text:
        // Remove the leading symbol
        // Left shift
        // Add the trailing symbol
        if ( i < N - M ) {
            thash = (d * (thash - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of thash, converting it
            // to positive
            if (thash < 0)
                thash = (thash + q);

        }
    }

    return result;


}