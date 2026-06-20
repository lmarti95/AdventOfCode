#include "Year2015Day2.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2015Day2::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day2::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    long result = 0;

    for (const auto& line : lines) {
        auto splitted = StringHelper::SplitString(line, "x");
        long l = std::stoi(splitted[0]);
        long w = std::stoi(splitted[1]);
        long h = std::stoi(splitted[2]);

        result += 2*l*w+2*l*h+2*w*h+std::min({l*w, l*h, w*h});
    }


    std::cout << "Result: " << result << std::endl;
}

void Year2015Day2::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    long result = 0;

    for (const auto& line : lines) {
        auto splitted = StringHelper::SplitString(line, "x");
        long l = std::stoi(splitted[0]);
        long w = std::stoi(splitted[1]);
        long h = std::stoi(splitted[2]);

        result += l*w*h + 2*(l+w+h - std::max({l,w,h}));
    }

    std::cout << "Result: " << result << std::endl;
}
