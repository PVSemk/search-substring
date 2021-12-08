//
// Created by pavel on 25.03.19.
//

#ifndef TASK1_KNUTH_MORRIS_PRATT_HPP
#define TASK1_KNUTH_MORRIS_PRATT_HPP

#include <string>
#include <vector>

std::vector<int> computePrefixFunction(std::string pat);
std::vector<int> searchKMP(std::string txt, std::string pat);

#endif //TASK1_KNUTH_MORRIS_PRATT_HPP
