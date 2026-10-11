#include "Year2015Day10.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

std::string ApplyTransformation(std::string& inputString);

void Year2015Day10::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day10::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    std::string result = lines[0];

    for (int i = 0; i < 40; i++) {
        result = ApplyTransformation(result);
    }

    std::cout << "Result: " << result.length() << std::endl;
}

void Year2015Day10::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    std::string result = lines[0];

    for (int i = 0; i < 50; i++) {
        result = ApplyTransformation(result);
    }

    std::cout << "Result: " << result.length() << std::endl;
}

std::string ApplyTransformation(std::string& inputString) {
    std::string result;

    char c = inputString[0];
    int j = 0;
    for (int i = 0; i < inputString.size(); i++) {
        if (inputString[i] != c) {
            result+=std::to_string(j);
            result+=c;
            j = 1;
            c = inputString[i];
        } else {
            j++;
        }
    }

    if ( j != 0) {
        result+=std::to_string(j);
        result+=c;
    }

    return std::move(result);
}