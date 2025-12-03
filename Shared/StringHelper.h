//
// Created by Marton Leitold on 02/12/2025.
//

#ifndef ADVENTOFCODE_STRINGHELPER_H
#define ADVENTOFCODE_STRINGHELPER_H

#include <vector>

class StringHelper {
public:
    static std::vector<std::string> SplitString(std::string line, std::string delimiter);
    static std::vector<int> StringToNumbers(std::string word);
};


#endif //ADVENTOFCODE_STRINGHELPER_H