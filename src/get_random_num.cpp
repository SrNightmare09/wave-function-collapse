#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

int get_random_num(int lower, int upper) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower, upper);
    int random_number = distr(gen);
    return random_number;
}