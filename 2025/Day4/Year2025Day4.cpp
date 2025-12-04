#include "Year2025Day4.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2025Day4::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day4::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] == '@') {
                if (CheckIfAccessible(i, j, lines)) {
                    result++;
                }
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day4::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;
    bool thereWasRemoved = true;
    while (thereWasRemoved) {
        thereWasRemoved = false;
        for (int i = 0; i < lines.size(); i++) {
            for (int j = 0; j < lines[i].size(); j++) {
                if (lines[i][j] == '@') {
                    if (CheckIfAccessible(i, j, lines)) {
                        result++;
                        lines[i][j] = '.';
                        thereWasRemoved = true;
                    }
                }
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

bool Year2025Day4::CheckIfAccessible(int i, int j, std::vector<std::string>& lines) {
    int count = 0;
    if (i != 0) {
        if (lines[i-1][j] == '@') {
            count++;
        }
        if (j != 0) {
            if (lines[i-1][j-1] == '@') {
                count++;
            }
        }
        if (j != lines[i-1].size()-1) {
            if (lines[i-1][j+1] == '@') {
                count++;
            }
        }
    }

    if (i != lines.size()-1) {
        if (lines[i+1][j] == '@') {
            count++;
        }
        if (j != 0) {
            if (lines[i+1][j-1] == '@') {
                count++;
            }
        }
        if (j != lines[i+1].size()-1) {
            if (lines[i+1][j+1] == '@') {
                count++;
            }
        }
    }

    if (j != 0) {
        if (lines[i][j-1] == '@') {
            count++;
        }
    }

    if (j != lines[i].size()-1) {
        if (lines[i][j+1] == '@') {
            count++;
        }
    }

    return count < 4;
}