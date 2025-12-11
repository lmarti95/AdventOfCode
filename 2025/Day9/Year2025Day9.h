#ifndef ADVENTOFCODE_YEAR2025DAY9_H
#define ADVENTOFCODE_YEAR2025DAY9_H

#include <string>
#include <vector>

#include <Point.h>

class Year2025Day9 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);
    static void SetUpTiles(std::vector<std::vector<char>> &tiles, std::vector<Point*>& points);
    static void PrintTiles(std::vector<std::vector<char>> &tiles);
};


#endif //ADVENTOFCODE_YEAR2025DAY9_H
