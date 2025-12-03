//
// Created by Marton Leitold on 01/12/2025.
//

#include "Year2025Day2.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2025Day2::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day2::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    auto ranges = StringHelper::SplitString(lines[0],",");

    long result = 0;

    for (auto range : ranges) {
        auto splitRanges = StringHelper::SplitString(range, "-");
        for (long i = std::stol(splitRanges[0]); i <= std::stol(splitRanges[1]); i++) {
            std::string range = std::to_string(i);
            if (TestIfSequenceRepeated(range)) {
                result += i;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day2::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    auto ranges = StringHelper::SplitString(lines[0],",");

    long result = 0;

    for (auto range : ranges) {
        auto splitRanges = StringHelper::SplitString(range, "-");
        for (long i = std::stol(splitRanges[0]); i <= std::stol(splitRanges[1]); i++) {
            std::string range = std::to_string(i);
            if (TestIfSequenceRepeatedPart2(range)) {
                result += i;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

bool Year2025Day2::TestIfSequenceRepeated(std::string word) {
    if (word.length() % 2 != 0) {
        return false;
    }
    for (int i = 0; i < word.length()/2; i++) {
        if (word[i] != word[i+word.length()/2]) {
            return false;
        }
    }

    return true;
}

bool Year2025Day2::TestIfSequenceRepeatedPart2(std::string word) {
    if (word.length() < 2) {
        return false;
    }

    for (int i = 1; i <= word.length()/2; i++) {
        if (CheckWordSequencePossibility(word, i)) {
            return true;
        }
    }

    return false;
}

bool Year2025Day2::CheckWordSequencePossibility(std::string word, int length) {
    auto parts = BreakUpWord(word, length);
    if (!CheckPartsLength(parts, length)) {
        return false;
    }
    for (int i = 1; i < parts.size(); i++) {
        for (int j = 0; j < parts[i].length(); j++) {
            if (parts[0][j] != parts[i][j]) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::string> Year2025Day2::BreakUpWord(std::string word, int length) {
    std::vector<std::string> result;
    while (word.length() >= length) {
        result.push_back(word.substr(0,length));
        word.erase(0,length);
    }
    if (word.length() != 0) {
        result.push_back(word);
    }

    return result;
}

bool Year2025Day2::CheckPartsLength(std::vector<std::string> parts, int length) {
    for (auto& part : parts) {
        if (part.length() != length) {
            return false;
        }
    }
    return true;
}