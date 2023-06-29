#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include "collapse.cpp"
#include "printboard.cpp"

std::vector<std::vector<char> > GRID = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};


int main () {
    collapse(GRID);
    printboard(GRID);
}
