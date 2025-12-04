#ifndef ADVENTOFCODE_YEAR2025DAY4_H
#define ADVENTOFCODE_YEAR2025DAY4_H

#include <string>
#include <vector>

class Year2025Day4 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static bool CheckIfAccessible(int i, int j, std::vector<std::string>& lines);
};


#endif //ADVENTOFCODE_YEAR2025DAY4_H
