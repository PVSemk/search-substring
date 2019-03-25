//
// Created by pavel on 25.03.19.
//

#ifndef TASK1_FINITE_AUTOMATA_H
#define TASK1_FINITE_AUTOMATA_H

#define ALPHABET_SIZE 256

#include <string>
#include <vector>

void computeTransFunct(std::string pat, int TF[][ALPHABET_SIZE]);
std::vector<int> searchFinAutomata(std::string, std::string);

#endif //TASK1_FINITE_AUTOMATA_H
