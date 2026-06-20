//
// Created by Marton Leitold on 17/12/2025.
//

#include "Utilities.h"

template <typename T>
void Utilities::DeleteVectorElements(std::vector<T> elements) {
    for (auto& element : elements) {
        delete element;
    }
}