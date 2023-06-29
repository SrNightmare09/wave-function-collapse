#include <iostream>
#include <vector>

void printboard(std::vector<std::vector<char> > &GRID) {
    for (int i = 0; i < GRID.size(); i++) {
        for (int j = 0; j < GRID[i].size(); j++) {
            std::cout << GRID[i][j] << " ";
        }

        std::cout << std::endl;
    }
}