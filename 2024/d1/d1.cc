#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
    std::fstream fs{};
    fs.open("input.txt");

    std::string text_block{};
    std::stringstream ss{};
    int row{};

    std::multiset<int> left{};
    std::multiset<int> right{};

    while (std::getline(fs, text_block))
    {
        ss.clear();
        ss.str(text_block);

        ss >> row;
        left.insert(row);
        ss >> row;
        right.insert(row);

    }
    fs.close();

    int total{};
    auto it2 {right.begin()};
    for (auto it1 = left.begin(); it1 != left.end();) 
    {
        total += abs(*it1 - *it2);

        it1++;
        it2++;
    }
    std::cout << total;
}
