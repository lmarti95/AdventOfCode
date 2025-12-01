//
// Created by Marton Leitold on 01/12/2025.
//

#ifndef ADVENTOFCODE_RUNTRANSLATE_H
#define ADVENTOFCODE_RUNTRANSLATE_H

#include <string>

class RunTranslate {
public:
    static void RunCorrectFunction(int year, int day, int inputType);
private:
    static void RunCorrectday2025(int day, std::string filenamePath);
    static std::string CreatePath(int year, int day, int inputType);
};


#endif //ADVENTOFCODE_RUNTRANSLATE_H