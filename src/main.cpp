#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>

class Tile {

public:
    int UP;
    int RIGHT;
    int BOTTOM;
    int LEFT;
    char ID;
    Tile(int, int, int, int, char); // clockwise from the top
    // blank - b, up - u, down - d, left - l, right - r
};

Tile::Tile(int UP, int RIGHT, int BOTTOM, int LEFT, char ID) {
    this->UP = UP;
    this->RIGHT = RIGHT;
    this->LEFT = LEFT;
    this->BOTTOM = BOTTOM;
    this->ID = ID;
}

std::vector<std::vector<char>> GRID = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

int get_random_num(int, int);
void start();
void update_grid(int, int, char);
void print_grid(); // testing purposes
std::vector<char> find_options(char);
void collapse_cell();

int main() {

    #pragma region INITIALIZE

    Tile BLANK = Tile(0, 0, 0, 0, 'b');
    Tile UP = Tile(1, 1, 0, 1, 'u');
    Tile LEFT = Tile(1, 0, 1, 1, 'l');
    Tile RIGHT = Tile(1, 1, 1, 0, 'r');
    Tile BOTTOM = Tile(0, 1, 1, 1, 'b');

    #pragma endregion

    collapse_cell();
    print_grid();

    return 0;
}

int get_random_num(int lower, int upper) { // inclusive of both limits
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower, upper);
    int random_num = distr(gen);
    return random_num;
}

void start() {
    // generate random index for a tile to put it at the upper corner of the grid
    std::vector<char> ids = {'b', 'u', 'l', 'r', 'd'};
    int random_index = get_random_num(0, 4);
    update_grid(0, 0, ids[random_index]);
    return;
}

void update_grid(int row, int column, char id) {
    GRID[row][column] = id;
    return;
}

void print_grid() {

    for (int i = 0; i < GRID.size(); i++) {
        for (int j = 0; j < GRID[i].size(); j++) {
            std::cout << GRID[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

std::vector<char> find_options(char ch) {

    std::unordered_map<char, std::vector<char>> valid_options = {
        {'u', {'u', 'd', 'l'}},
        {'d', {'u', 'd', 'l'}},
        {'r', {'u', 'd', 'l'}},
        {'l', {'r', 'b'}},
        {'b', {'r', 'b'}},
    };

    auto it = valid_options.find(ch);
    std::vector<char> valid = it->second;

    return valid;

}

void collapse_cell() {

    int random_index;

    for (int i = 0; i < GRID[0].size(); i++) {
        if (i == 0) {
            start();
            continue;
        }
        std::vector<char> valid_options = find_options(GRID[0][i - 1]);
        random_index = get_random_num(0, valid_options.size() - 1);
        update_grid(0, i, valid_options[random_index]);
    }

    // MAKE SIMILAR FUNCTIONALITY FOR CHECKING TOP NEIGHBORS AS WELl

}
