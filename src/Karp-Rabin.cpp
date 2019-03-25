//
// Created by pavel on 25.03.19.
//
#include "Karp-Rabin.h"

#define d 256 // d is the number of characters in alphabet



std::vector<int> searchKarpRabin(std::string s, std::string t, int q) // s - search, t - template, q - prime number
{
    std::vector<int> result;
    int h(1);

    // Count h variable in order to recount hash later
    // (It will help to remove the leading symbol)
    // Formula: h = pow(d, t.length() - 1) % q
    for (int i(0); i < t.length() - 1; i++)
        h = d * h % q;

    int thash(0), shash(0); // hash value for the template and string

    // Calculate value for the template and the first windows of the string
    for (int i(0); i < t.length(); i++)
    {
        thash = (d*thash + t[i])%q;
        shash = (d*shash + s[i])%q;
    }

    // Check all possible shifts
    for (int i(0); i <= s.length() - t.length(); i++)
    {

    }


}