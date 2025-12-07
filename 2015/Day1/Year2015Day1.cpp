#include "Year2015Day1.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2015Day1::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day1::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    for (char c : lines[0]) {
        if (c == '(') {
            result++;
        }
        else {
            result--;
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day1::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int count = 0;
    int result;

    for (int i = 0; i < lines[0].size(); i++) {
        if (lines[0][i] == '(') {
            count++;
        }
        else {
            count--;
            if (count == -1) {
                result = i+1;
                break;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}
