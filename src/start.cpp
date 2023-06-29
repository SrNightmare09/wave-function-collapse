#include <iostream>
#include <vector>
#ifndef GET_RANDOM_NUM
#define GET_RANDOM_NUM
#include "get_random_num.cpp"
#endif


void start(std::vector<std::vector<char> > &GRID) {
    std::vector<char> options = {'d', 'u', 'l', 'r', 'b'};

    int rand_index = get_random_num(0, options.size() - 1);
    GRID[0][0] = options[rand_index];
}