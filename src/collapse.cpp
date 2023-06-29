#include <iostream>
#include <vector>
#include "roof_collapse.cpp"
#include "left_collapse.cpp"
#include "start.cpp"
#include "update_grid.cpp"


void collapse(std::vector<std::vector<char> > &GRID) {
    for (int i = 0; i < GRID.size(); i++) {
        for (int j = 0; j < GRID[i].size(); j++) {

            if (i == 0 && j == 0) {
                start(GRID);
                continue;
            }

            if (i == 0) {
                std::vector<char> valid_options = left_collapse(GRID[i][j-1]);
                update_grid(i, j, valid_options,GRID);
                continue;
            }

            if (j == 0) {
                std::vector<char> valid_options = roof_collapse(GRID[i - 1][j]);
                update_grid(i, j, valid_options,GRID);
                continue;
            }

            if (i != 0 && j != 0) {
                std::vector<char> valid_options_up = roof_collapse(GRID[i - 1][j]);
                std::vector<char> valid_options_left = left_collapse(GRID[i][j - 1]);
                std::sort(valid_options_up.begin(), valid_options_up.end());
                std::sort(valid_options_left.begin(), valid_options_left.end());
                std::vector<char> intersection;

                std::set_intersection(valid_options_left.begin(), valid_options_left.end(), valid_options_up.begin(), valid_options_up.end(), std::back_inserter(intersection));

                update_grid(i, j, intersection,GRID);
                continue;
            }

        }
    }
}