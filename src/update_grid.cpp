#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#ifndef GET_RANDOM_NUM
#define GET_RANDOM_NUM
#include "get_random_num.cpp"
#endif

void update_grid(int row, int col, std::vector<char> options,std::vector<std::vector<char> > &GRID) {
    int rand_num = get_random_num(0, options.size() - 1);
    GRID[row][col] = options[rand_num];
}