//
// Created by Marton Leitold on 17/12/2025.
//

#include "IndicatorLight.h"

IndicatorLight::IndicatorLight(int size){
    diagram = std::vector<int>(size);
}

bool IndicatorLight::operator==(IndicatorLight& other) {
    if (this->diagram.size() != other.diagram.size()) {
        return false;
    }

    for (int i = 0; i < this->diagram.size(); i++) {
        if (this->diagram[i] != other.diagram[i])
            return false;
    }

    return true;
}