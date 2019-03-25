//
// Created by pavel on 25.03.19.
//
#include "Finite-Automata.h"

void computeTransFunct(std::string pat, int TF[][ALPHABET_SIZE])
{
    int lps(0);
    unsigned long M(pat.length());
    // Fill the first row values
    for (int x(0); x < ALPHABET_SIZE; x++)
        TF[0][x] = 0;
    TF[0][pat[0]] = 1;
    // Fill values of other rows
    for (int i(1); i <= M; i++)
    {
        for (int x(0); x < ALPHABET_SIZE; x++)
            TF[i][x] = TF[lps][x];

        TF[i][pat[i]] = i + 1;

        if (i < M)
            lps = TF[lps][pat[i]];
    }

}

std::vector<int> searchFinAutomata(std::string txt, std::string pat)
{
    unsigned long N(txt.length()), M(pat.length());
    std::vector<int> res;
    int TF[M+1][ALPHABET_SIZE];

    computeTransFunct(pat, TF);

    // Work with the text
    int i, j=0;
    for (i = 0; i < N; i++)
    {
        j = TF[j][txt[i]];
        if (j == M)
        res.push_back(i - M + 1);
    }

    return res;
}