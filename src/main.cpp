#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

std::vector<std::vector<char>> GRID = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

int get_random_num(int lower, int upper) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower, upper);
    int random_number = distr(gen);
    return random_number;
}

void start() {
    std::vector<char> options = {'d', 'u', 'l', 'r', 'b'};

    int rand_index = get_random_num(0, options.size() - 1);
    GRID[0][0] = options[rand_index];
}

std::vector<char> roof_collapse(char ch) {
    std::unordered_map<char, std::vector<char>> possible_connections = {
        {'d', {'l', 'r', 'u'}},
        {'u', {'b', 'd'}},
        {'l', {'l', 'r', 'u'}},
        {'r', {'l', 'r', 'u'}},
        {'b', {'b', 'd'}}
    };

    std::vector<char> options;

    auto it = possible_connections.find(ch);

    options = it->second;

    return options;
}

std::vector<char> left_collapse(char ch) {
    std::unordered_map<char, std::vector<char>> possible_connections = {
        {'d', {'l', 'd', 'u'}},
        {'u', {'l', 'd', 'u'}},
        {'l', {'b', 'r'}},
        {'r', {'l', 'd', 'u'}},
        {'b', {'b', 'r'}}
    };

    std::vector<char> options;

    auto it = possible_connections.find(ch);

    options = it->second;

    return options;
}

void update_grid(int row, int col, std::vector<char> options) {
    int rand_num = get_random_num(0, options.size() - 1);
    GRID[row][col] = options[rand_num];
}

void collapse() {
    for (int i = 0; i < GRID.size(); i++) {
        for (int j = 0; j < GRID[i].size(); j++) {

            if (i == 0 && j == 0) {
                start();
                continue;
            }

            if (i == 0) {
                std::vector<char> valid_options = left_collapse(GRID[i][j-1]);
                update_grid(i, j, valid_options);
                continue;
            }

            if (j == 0) {
                std::vector<char> valid_options = roof_collapse(GRID[i - 1][j]);
                update_grid(i, j, valid_options);
                continue;
            }

            if (i != 0 && j != 0) {
                std::vector<char> valid_options_up = roof_collapse(GRID[i - 1][j]);
                std::vector<char> valid_options_left = left_collapse(GRID[i][j - 1]);
                std::sort(valid_options_up.begin(), valid_options_up.end());
                std::sort(valid_options_left.begin(), valid_options_left.end());
                std::vector<char> intersection;

                std::set_intersection(valid_options_left.begin(), valid_options_left.end(), valid_options_up.begin(), valid_options_up.end(), std::back_inserter(intersection));

                update_grid(i, j, intersection);
                continue;
            }

        }
    }
}

void printboard() {
    for (int i = 0; i < GRID.size(); i++) {
        for (int j = 0; j < GRID[i].size(); j++) {
            std::cout << GRID[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main () {
    collapse();
    printboard();
}
