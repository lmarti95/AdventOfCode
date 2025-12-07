#include "Year2025Day6.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2025Day6::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day6::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    long long result = 0;

    std::vector<std::vector<long long>> columns(GetNumberOfColumns(lines[0]));

    for (auto& line : lines) {
        while (line.find("  ") != std::string::npos) {
            StringHelper::ChangePartsOfString(line, "  ", " ");
        }
        if (line[0] == ' ') {
            StringHelper::ChangePartsOfString(line, " ", "");
        }
        if (line[line.length()-1] == ' ') {
            line = line.substr(0, line.length()-1);
        }
        if (line.find("*") != std::string::npos) {
            continue;
        }
        auto parts = StringHelper::SplitString(line, " ");

        for (int i = 0; i < parts.size(); i++) {
            columns[i].push_back(std::stoll(parts[i]));
        }
    }

    auto operators = StringHelper::SplitString(lines[lines.size()-1], " ");
    result = GetResult(operators, columns);

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day6::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    long long result = 0;

    std::vector<std::vector<long long>> correctColumns(GetNumberOfColumns(lines[0]));

    int currentOperatorColumn = 0;
    for (int i = 0; i < lines[0].length();i++) {
        bool foundResult = false;
        std::string tempResult;
        for (int j = 0; j < lines.size()-1; j++) {
            if (lines[j][i] == ' ') {
                continue;
            }
            foundResult = true;
            tempResult += lines[j][i];
        }
        if (foundResult) {

            correctColumns[currentOperatorColumn].push_back(std::stoll(tempResult));
            continue;
        }
        currentOperatorColumn++;
    }

    while (lines[lines.size()-1].find("  ") != std::string::npos) {
        StringHelper::ChangePartsOfString(lines[lines.size()-1], "  ", " ");
    }

    auto operators = StringHelper::SplitString(lines[lines.size()-1], " ");
    result = GetResult(operators, correctColumns);

    std::cout << "Result: " << result << std::endl;
}

int Year2025Day6::GetNumberOfColumns(std::string line) {
    while (line.find("  ") != std::string::npos) {
        StringHelper::ChangePartsOfString(line, "  ", " ");
    }
    auto parts = StringHelper::SplitString(line, " ");

    return parts.size();
}

long long Year2025Day6::GetResult(std::vector<std::string> operators, std::vector<std::vector<long long>> columns)  {
    long long result = 0;
    for (int i = 0; i < operators.size(); i++) {
        long long temp = 0;
        if (operators[i] == "*") {
            temp = 1;
        }
        for (auto number : columns[i]) {
            if (operators[i] == "*") {
                temp *= number;
            }
            else {
                temp += number;
            }
        }
        result += temp;
        std::cout << result << std::endl;
    }
    return result;
}