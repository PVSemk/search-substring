//
// Created by pavel on 25.03.19.
//
#include "Karp-Rabin.h"

#define d 256 // d is the number of characters in alphabet



std::vector<int> searchKarpRabin(std::string txt, std::string pat, int q) // q - prime number
{
    std::vector<int> result;
    int h(1);

    // Count h variable in order to recount hash later
    // (It will help to remove the leading symbol)
    // Formula: h = pow(d, pat.length() - 1) % q
    for (int i(0); i < pat.length() - 1; i++)
        h = d * h % q;

    int thash(0), shash(0); // hash value for the template and string

    // Calculate value for the template and the first windows of the string
    for (int i(0); i < pat.length(); i++)
    {
        thash = (d * thash + pat[i]) % q;
        shash = (d * shash + txt[i]) % q;
    }

    // Check all possible shifts
    for (int i(0), j; i <= txt.length() - pat.length(); i++)
    {
        // Check hash values of the current window and the template
        // If they are equal, compare all symbols in order to exclude collision-cases
        if (shash == thash)
        {
            // Check equality of txt[i...i + pat.length - 1] and template
            for (j = 0; j < pat.length(); j++)
                if (txt[j + i] != pat[j])
                    break;

            // Add a current shift into the result only if all the symbols are equal
            if (j == pat.length())
            {
                result.push_back(i);
            }
        }
    }


}