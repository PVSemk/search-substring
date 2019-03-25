//
// Created by pavel on 25.03.19.
//

#include "Brute-Force.h"

#include <iostream>

int main()
{
    std::string t = "ABC";
    std::string s = "ABCasdABCaaABCddABCddABC";

    std::vector<int> result = bruteForceSearch(s, t);

    for (int shift : result)
        std::cout << "Found match with shift: " << shift << std::endl;

    return 0;
}