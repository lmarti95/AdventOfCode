//
// Created by Marton Leitold on 02/12/2025.
//

#include "StringHelper.h"

std::vector<std::string> StringHelper::SplitString(std::string line, std::string delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line);

    return tokens;
}

std::vector<int> StringHelper::StringToNumbers(std::string word) {
    std::vector<int> result;
    for (char c : word) {
        result.push_back(c-'0');
    }
    return result;
}