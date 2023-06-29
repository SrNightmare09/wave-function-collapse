#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>




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