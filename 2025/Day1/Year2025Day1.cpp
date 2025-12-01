//
// Created by Marton Leitold on 01/12/2025.
//

#include "Year2025Day1.h"
#include "../../Shared/ReadHelper.h"

#include <iostream>

void Year2025Day1::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day1::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int password = 0;

    int position = 50;
    for (auto& line : lines) {
        position += ConvertTurn(line);
        while (position >= 100) {
            position -= 100;
        }
        while (position < 0) {
            position += 100;
        }

        if (position == 0) {
            password++;
        }
    }

    std::cout << "Password: " << password << std::endl;
}

void Year2025Day1::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int password = 0;

    int position = 50;
    for (auto& line : lines) {
        int convertValue = ConvertTurn(line);
        if (position == 0 || position == 100) {
            if (convertValue > 0) {
                position = convertValue;
            }
            else {
                position = 100 + convertValue;
            }
        }
        else {
            position += convertValue;
        }

        std::cout << position;
        while (position > 100) {
            password++;
            position -= 100;
        }
        while (position < 0) {
            password++;
            position += 100;
        }

        std::cout << " " <<  position << " " << password << std::endl;

        if (position == 0 || position == 100) {
            password++;
        }
    }

    std::cout << "Password: " << password << std::endl;
}

int Year2025Day1::ConvertTurn(std::string line) {
    int result = std::stoi(line.substr(1));
    if (line[0] == 'L') {
        result = result * -1;
    }

    return result;
}

