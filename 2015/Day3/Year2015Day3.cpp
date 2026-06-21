#include "Year2015Day3.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>
#include <set>

void Year2015Day3::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day3::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    std::set<std::pair<int, int>> visitedHouses;

    int x{0}, y{0};
    visitedHouses.emplace(std::make_pair(x, y));

    for (const auto& line : lines) {
        for (char c : line) {
            if (c == '^' ) {
                x++;
            }
            else if (c == 'v') {
                x--;
            }
            else if (c == '<') {
                y--;
            } else {
                y++;
            }
            visitedHouses.emplace(std::make_pair(x, y));
        }
    }

    result = visitedHouses.size();

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day3::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;
    std::set<std::pair<int, int>> visitedHouses;

    int santaX{0}, santaY{0}, robotX{0}, robotY{0};
    visitedHouses.emplace(std::make_pair(santaX, santaY));

    int i = 0;
    for (const auto& line : lines) {
        for (char c : line) {
            if (c == '^' ) {
                if (i % 2 == 0) {
                    santaX++;
                }
                else {
                    robotX++;
                }
            }
            else if (c == 'v') {
                if (i % 2 == 0) {
                    santaX--;
                }
                else {
                    robotX--;
                }
            }
            else if (c == '<') {
                if (i % 2 == 0) {
                    santaY--;
                }
                else {
                    robotY--;
                }
            } else {
                if (i % 2 == 0) {
                    santaY++;
                }
                else {
                    robotY++;
                }
            }
            if (i % 2 == 0) {
                visitedHouses.emplace(std::make_pair(santaX, santaY));
            }
            else {
                visitedHouses.emplace(std::make_pair(robotX, robotY));
            }
            i++;
        }
    }

    result = visitedHouses.size();

    std::cout << "Result: " << result << std::endl;
}
