//
// Created by pavel on 25.03.19.
//

#include "Karp-Rabin.h"

#include <iostream>

int main()
{
    std::vector<int> shift = {0,6,11,16,21};
    std::string t = "ABC";
    std::string s = "ABCasdABCaaABCddABCddABC";
    std::vector<int> result = searchKarpRabin(s, t, 13);
    for (int shift : result)
        std::cout << "Found match with shift: " << shift << std::endl;
    return 0;
}//
// Created by pavel on 25.03.19.
//

