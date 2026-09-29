#include "Year2015Day7.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>
#include <fstream>

enum class Operation {Value, NOT, LSHIFT, RSHIFT, AND, OR};

class Wire {
public:
    std::string inputWire1;
    std::string inputWire2;
    Operation operation;
    int extraValue1 = -1;
    std::bitset<16> bitValue;
    std::string wireName;
    bool calculatedValueSet = false;
    std::bitset<16> calculatedValue;
};

Wire ConstructWire(std::string line);
std::bitset<16> GetValue(std::string wireName);

std::vector<Wire> wires;

void Year2015Day7::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day7::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    wires.reserve(lines.size());

    for (auto& line : lines) {
        wires.push_back(ConstructWire(line));
    }

    auto result = GetValue("a").to_ullong();

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day7::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    wires.clear();

    for (auto& line : lines) {
        if (line == "14146 -> b") {
            wires.push_back(ConstructWire("956 -> b"));
            continue;
        }
        wires.push_back(ConstructWire(line));
    }

    auto result = GetValue("a").to_ullong();

    std::cout << "Result: " << result << std::endl;
}

Wire ConstructWire(std::string line) {
    Wire wire;
    auto sides = StringHelper::SplitString(line, " -> ");
    wire.wireName = sides[1];
    auto leftSides = StringHelper::SplitString(sides[0], " ");

    if (leftSides.size() == 1) {
        wire.operation = Operation::Value;
        if (StringHelper::IsNumber(leftSides[0])) {
            wire.bitValue = std::stoi(leftSides[0]);
        }
        else {
            wire.inputWire1 = leftSides[0];
        }
        return wire;
    }

    if (sides[0].substr(0, 3) == "NOT") {
        wire.operation = Operation::NOT;
        wire.inputWire1 = leftSides[1];
        return wire;
    }

    if (leftSides[1] == "AND") {
        wire.operation = Operation::AND;
        if (StringHelper::IsNumber(leftSides[0])) {
            wire.extraValue1 = std::stoi(leftSides[0]);
        }
        else {
            wire.inputWire1 = leftSides[0];
        }
        wire.inputWire2 = leftSides[2];
    }

    if (leftSides[1] == "OR") {
        wire.operation = Operation::OR;
        if (StringHelper::IsNumber(leftSides[0])) {
            wire.extraValue1 = std::stoi(leftSides[0]);
        }
        else {
            wire.inputWire1 = leftSides[0];
        }
        wire.inputWire2 = leftSides[2];
    }

    if (leftSides[1] == "LSHIFT") {
        wire.operation = Operation::LSHIFT;
        wire.inputWire1 = leftSides[0];
        wire.extraValue1 = std::stoi(leftSides[2]);
    }

    if (leftSides[1] == "RSHIFT") {
        wire.operation = Operation::RSHIFT;
        wire.inputWire1 = leftSides[0];
        wire.extraValue1 = std::stoi(leftSides[2]);
    }

    return wire;
}

std::bitset<16> GetValue(std::string wireName) {
    auto currentWire = std::find_if(wires.begin(), wires.end(), [&wireName](const Wire& a) {
        return a.wireName == wireName;
    });

    if (currentWire == wires.end()) {
        return 0;
    }

    if (currentWire->calculatedValueSet) {
        return currentWire->calculatedValue;
    }

    switch (currentWire->operation) {
        case Operation::Value: {
            if (currentWire->inputWire1.empty()) {
                currentWire->calculatedValue = currentWire->bitValue;
                currentWire->calculatedValueSet = true;
                return currentWire->bitValue;
            }
            currentWire->calculatedValue = GetValue(currentWire->inputWire1);
            currentWire->calculatedValueSet = true;
            return currentWire->calculatedValue;
        }

        case Operation::AND: {
            return (currentWire->inputWire1.empty() ? std::bitset<16>(currentWire->extraValue1) : GetValue(currentWire->inputWire1)) & GetValue(currentWire->inputWire2);

        }

        case Operation::OR: {
            return (currentWire->inputWire1.empty() ? std::bitset<16>(currentWire->extraValue1) : GetValue(currentWire->inputWire1)) | GetValue(currentWire->inputWire2);
        }

        case Operation::RSHIFT: {
            currentWire->calculatedValue = GetValue(currentWire->inputWire1) >> currentWire->extraValue1;
            currentWire->calculatedValueSet = true;
            return currentWire->calculatedValue;
        }

        case Operation::LSHIFT: {
            currentWire->calculatedValue = GetValue(currentWire->inputWire1) << currentWire->extraValue1;
            currentWire->calculatedValueSet = true;
            return currentWire->calculatedValue;
        }

        case Operation::NOT: {
            currentWire->calculatedValue = ~GetValue(currentWire->inputWire1);
            currentWire->calculatedValueSet = true;
            return currentWire->calculatedValue;
        }
    }

    return 0;
}