#ifndef ADVENTOFCODE_YEAR2025DAY8_H
#define ADVENTOFCODE_YEAR2025DAY8_H

#include <string>
#include <vector>

#include "Point.h"

class Year2025Day8 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static bool IsAllConnecred(std::vector<std::vector<Point*>>& circuits, int size);
};


#endif //ADVENTOFCODE_YEAR2025DAY8_H
