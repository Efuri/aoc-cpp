#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
    std::fstream fs{};
    fs.open("input.txt");

    std::string text_block{};
    std::stringstream ss{};
    int curr{};
    int total{};

    while (std::getline(fs, text_block))
    {
        ss.clear();
        ss.str(text_block);

        bool good {true};
        bool first{true};
        bool second{false};
        bool asc{};
        int prev{};
        while (ss >> curr)
        {
            if (!good) continue;

            if (first)
            {
                first=false;
                second = true;
                prev = curr;
                continue;
            }
            if (second)
            {
                second = false;
                asc = (prev < curr) ? true : false;
            }

            if (prev == curr)
            {
                good = false;
                continue;
            }
            if (prev < curr)
            {
                if (asc)
                {
                    if ((curr - prev) > 3) good = false;
                    prev = curr;
                    continue;
                }
                else
                {
                    good = false;
                    continue;
                }
            }
            if (prev > curr)
            {
                if (!asc)
                {
                    if ((prev - curr) > 3) good = false;
                    prev = curr;
                    continue;
                }
                else
                {
                    good = false;
                    continue;
                }
            }

        }
        if (good) total++;
    }
    fs.close();
    std::cout << total;
}
