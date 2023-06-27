#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<char>> GRID = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

std::vector<char> left_collapse(char);
std::vector<char> up_collapse(char);
std::vector<char> find_intersection(std::vector<char>, std::vector<char>);
int get_random_num(int, int);

int main() {

    return 0;

}

std::vector<char> left_collapse(char ch) {
    std::unordered_map<char, std::vector<char>> valid_options = {
        {'b', {'b', 'r'}},
        {'u', {'d', 'l', 'u'}},
        {'r', {'d', 'l', 'u'}},
        {'l', {'b', 'r'}},
        {'d', {'d', 'l', 'u'}}
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

std::vector<char> find_intersection(std::vector<char> a, std::vector<char> b) {
    std::vector<char> intersection;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(intersection));
    return intersection;
}

int get_random_num(int lower, int upper) { // inclusive of both limits
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower, upper);
    int random_num = distr(gen);
    return random_num;
}