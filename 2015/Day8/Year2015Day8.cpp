#include "Year2015Day8.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

int GetMemoryCharacters(std::string code);
int GetExtendedMemoryCharacters(std::string code);


void Year2015Day8::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day8::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int literalCount = 0;
    int memoryCount = 0;

    for (auto& line : lines) {
        literalCount += line.length();
        memoryCount += GetMemoryCharacters(line)-2;
    }

    std::cout << "Result: " << literalCount - memoryCount << std::endl;
}

void Year2015Day8::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int literalCount = 0;
    int extendedCount = 0;

    for (auto& line : lines) {
        literalCount += line.length();
        extendedCount += GetExtendedMemoryCharacters(line)+4;
    }

    std::cout << "Result: " << extendedCount - literalCount << std::endl;
}

int GetMemoryCharacters(std::string code) {
    int extraCount = 0;
    while (code.find("\\\\") != std::string::npos) {
        code.erase(code.find("\\\\"), 2);
        extraCount++;
    }

    while (code.find("\\\"") != std::string::npos) {
        code.erase(code.find("\\\""), 2);
        extraCount++;
    }

    while (code.find("\\x") != std::string::npos) {
        code.erase(code.find("\\x"), 4);
        extraCount++;
    }

    return extraCount + code.length();
}

int GetExtendedMemoryCharacters(std::string code) {
    int extraCount = code.length();
    while (code.find("\\\\") != std::string::npos) {
        code.erase(code.find("\\\\"), 2);
        extraCount+=2;
    }

    while (code.find("\\\"") != std::string::npos) {
        code.erase(code.find("\\\""), 2);
        extraCount+=2;
    }

    while (code.find("\\x") != std::string::npos) {
        code.erase(code.find("\\x"), 4);
        extraCount++;
    }

    return extraCount;
}
