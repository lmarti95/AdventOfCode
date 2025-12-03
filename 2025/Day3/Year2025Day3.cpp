//
// Created by Marton Leitold on 01/12/2025.
//

#include "Year2025Day3.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2025Day3::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day3::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int sum = 0;

    for (auto& line : lines) {
        auto numbers = StringHelper::StringToNumbers(line);
        sum += GetJoltage(numbers);
    }

    std::cout << "Result: " << sum << std::endl;
}

void Year2025Day3::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    long long sum = 0;

    for (auto& line : lines) {
        auto numbers = StringHelper::StringToNumbers(line);
        sum += GetJoltage(numbers,12);
    }

    std::cout << "Result: " << sum << std::endl;
}

int Year2025Day3::GetJoltage(std::vector<int> batteries) {
    int leftMax = 0;
    int rightMax = 0;
    for (int i = 1; i < batteries.size(); i++) {
        if (leftMax < batteries[i-1]) {
            leftMax = batteries[i-1];
            rightMax = batteries[i];
            continue;
        }
        if (rightMax < batteries[i]) {
            rightMax = batteries[i];
        }
    }

    return leftMax*10+rightMax;
}

long long Year2025Day3::GetJoltage(std::vector<int> batteries, int numberOfBatteries) {
    std::vector<int> joltages(numberOfBatteries);

    for (int i = numberOfBatteries-1; i < batteries.size(); i++) {
        bool needsReset = false;
        for (int j = 0; j < numberOfBatteries; j++) {
            if (needsReset) {
                joltages[j] = batteries[j+i-numberOfBatteries+1];
                continue;
            }
            if (joltages[j] < batteries[j+i-numberOfBatteries+1]) {
                needsReset = true;
                joltages[j] = batteries[j+i-numberOfBatteries+1];
            }
        }
    }

    long multiplier = 1;
    long long result = 0;
    for (int i = joltages.size()-1; i >= 0; i--) {
        result += joltages[i]*multiplier;
        multiplier *=10;
    }

    return result;
}