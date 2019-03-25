//
// Created by pavel on 25.03.19.
//
#include "Knuth-Morris-Pratt.h"

#include <iostream>

int main()
{
    std::string t = "ABC";
    std::string s = "ABCasdABCaaABCddABCddABC";
    std::vector<int> result = searchKMP(s, t);
    for (int shift : result)
        std::cout << "Found match with shift: " << shift << std::endl;
    return 0;
}
