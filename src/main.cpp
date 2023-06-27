#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<char>> GRID;

int main() {

    return 0;

}

std::vector<char> left_collapse(char ch) {
    std::unordered_map<char, std::vector<char>> valid_options = {
        {'b', {'r', 'b'}},
        {'u', {'u', 'd', 'l'}},
        {'r', {'u', 'd', 'l'}},
        {'l', {'r', 'b'}},
        {'d', {'u', 'd', 'l'}}
    };

    auto it = valid_options.find(ch);
    std::vector<char> valid = it->second;
    return valid;
}

std::vector<char> up_collapse(char ch) {
    std::unordered_map<char, std::vector<char>> valid_options = {
        {'b', {'b', 'd'}},
        {'u', {'b', 'd'}},
        {'r', {'u', 'l', 'r'}},
        {'l', {'u', 'l', 'r'}},
        {'d', {'u', 'l', 'r'}}
    };

    auto it = valid_options.find(ch);
    std::vector<char> valid = it-> second;
    return valid;
}