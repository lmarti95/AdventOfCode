//
// Created by Marton Leitold on 01/12/2025.
//

#ifndef ADVENTOFCODE_YEAR2025DAY2_H
#define ADVENTOFCODE_YEAR2025DAY2_H

#include <string>
#include <vector>

class Year2025Day2 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static bool TestIfSequenceRepeated(std::string word);
    static bool TestIfSequenceRepeatedPart2(std::string word);

    static bool CheckWordSequencePossibility(std::string word, int length);
    static std::vector<std::string> BreakUpWord(std::string word, int length);
    static bool CheckPartsLength(std::vector<std::string> parts, int length);
};


#endif //ADVENTOFCODE_YEAR2025DAY2_H