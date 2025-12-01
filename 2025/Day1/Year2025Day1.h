//
// Created by Marton Leitold on 01/12/2025.
//

#ifndef ADVENTOFCODE_YEAR2025DAY1_H
#define ADVENTOFCODE_YEAR2025DAY1_H

#include <string>

class Year2025Day1 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static int ConvertTurn(std::string line);
};


#endif //ADVENTOFCODE_YEAR2025DAY1_H