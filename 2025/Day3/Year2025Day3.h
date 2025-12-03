//
// Created by Marton Leitold on 01/12/2025.
//

#ifndef ADVENTOFCODE_YEAR2025DAY3_H
#define ADVENTOFCODE_YEAR2025DAY3_H

#include <string>
#include <vector>

class Year2025Day3 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static int GetJoltage(std::vector<int> batteries);
    static long long GetJoltage(std::vector<int> batteries, int numberOfBatteries);
};


#endif //ADVENTOFCODE_YEAR2025DAY3_H