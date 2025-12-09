//
// Created by Marton Leitold on 08/12/2025.
//

#include "Point.h"

Point::Point(std::string X, std::string Y, std::string Z, int i) {
    this->X = std::stoi(X);
    this->Y = std::stoi(Y);
    this->Z = std::stoi(Z);
    this->i = i;
}

double Point::GetDistance(Point* othetPoint) {
    return sqrt(std::pow((this->X - othetPoint->X),2)+std::pow((this->Y - othetPoint->Y),2) +std::pow((this->Z - othetPoint->Z),2));
}