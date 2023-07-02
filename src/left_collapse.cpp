#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <map>

std::vector<char> left_collapse(char ch) {
    std::map<char, std::vector<char>> possible_connections = {
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
