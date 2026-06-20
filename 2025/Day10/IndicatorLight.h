//
// Created by Marton Leitold on 17/12/2025.
//

#ifndef ADVENTOFCODE_INDICATORLIGHT_H
#define ADVENTOFCODE_INDICATORLIGHT_H

#include <vector>

class IndicatorLight {
public:
    IndicatorLight(int size);
    IndicatorLight() {}
    std::vector<int> diagram;
    int steps;
    bool operator==(IndicatorLight& other);
};


#endif //ADVENTOFCODE_INDICATORLIGHT_H