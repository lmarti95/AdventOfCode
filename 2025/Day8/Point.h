//
// Created by Marton Leitold on 08/12/2025.
//

#ifndef ADVENTOFCODE_POINT_H
#define ADVENTOFCODE_POINT_H

#include <string>

class Point {
public:
    Point(std::string X, std::string Y, std::string Z, int i);
    double GetDistance(Point* othetPoint);
    int i;
    int X;
    int Y;
    int Z;
    int circuit = -1;
    bool partOfCircuit = false;
};



#endif //ADVENTOFCODE_POINT_H