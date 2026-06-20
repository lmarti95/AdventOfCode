#include "Year2025Day10.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/Utilities.h"
#include "../../Shared/StringHelper.h"

#include <iostream>
#include <map>
#include <numeric>
#include <random>

#include "Button.h"
#include "IndicatorLight.h"

static std::vector<IndicatorLight*> allLights;
static int maxSteps = 0;

void Year2025Day10::Run(std::string filenamePath) {
    //RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day10::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    std::vector<IndicatorLight*> finalLights;
    std::vector<std::vector<Button*>*> buttons;

    for (auto& line : lines) {
        IndicatorLight* light = CreateIndicatorLight(line);
        finalLights.push_back(light);
        buttons.push_back(CreateButtons(line));
    }

    for (int i = 0; i < finalLights.size();i++) {
        result += StepsUntilLight(finalLights[i], buttons[i]);
    }

    DeleteVectorElements(allLights);
    for (auto innerButtons : buttons) {
        DeleteVectorElements(*innerButtons);
    }
    DeleteVectorElements(buttons);

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day10::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    long result = 0;

    for (auto& line : lines) {
        IndicatorLight* light = CreateJoltageLight(line);
        std::vector<Button*>* buttons = CreateButtons(line);
        std::vector<std::vector<int>*>* matrix = CreateMatrix(light, buttons);
        SolveMatrix(matrix);

        delete light;

        DeleteVectorElements(*buttons);
        delete buttons;

        DeleteVectorElements(*matrix);
        delete matrix;
    }

    std::cout << "Result: " << result << std::endl;
}


IndicatorLight* Year2025Day10::CreateIndicatorLight(std::string line) {
    IndicatorLight* light = new IndicatorLight();
    allLights.push_back(light);
    line = line.substr(1, line.find(']')-1);
    for (auto c : line) {
        if (c == '.') {
            light->diagram.push_back(0);
        }
        else {
            light->diagram.push_back(1);
        }
    }

    return  light;
}

std::vector<Button*>* Year2025Day10::CreateButtons(std::string line) {
    std::vector<Button*>* buttons = new std::vector<Button*>();
    line = line.substr(line.find(']')+2);
    line = line.substr(0, line.find('{')-1);
    auto parts = StringHelper::SplitString(line, " ");
    for (auto& part : parts) {
        part = part.substr(1, part.length()-2);
        auto innerParts = StringHelper::SplitString(part, ",");
        Button* b = new Button();
        for (auto innerPart : innerParts) {
            b->lights.push_back(std::stoi(innerPart));
        }
        buttons->push_back(b);
    }

    return buttons;
}

int Year2025Day10::StepsUntilLight(IndicatorLight* final, std::vector<Button*>* buttons) {
    IndicatorLight* light = new IndicatorLight(final->diagram.size());
    allLights.push_back(light);
    light->steps = 0;

    int maxDistance = final->diagram.size();

    maxSteps = maxDistance;

    std::map<int, std::vector<IndicatorLight*>> lightsToExplore;
    for (int i = 0; i <= maxDistance; i++) {
        lightsToExplore[i];
    }

    std::vector<IndicatorLight*> visitedLights;

    lightsToExplore[DistanceBetweenLightDiagrams(light, final)].push_back(light);
    auto nextLight = GetNextLight(lightsToExplore, maxDistance);

    int result = -1;

    while (nextLight != nullptr) {
        if (VisitedBefore(nextLight, visitedLights)) {
            nextLight = GetNextLight(lightsToExplore, maxDistance);
            continue;
        }

        visitedLights.push_back(nextLight);

        if (DistanceBetweenLightDiagrams(final, nextLight) == 0) {
            if (result == -1) {
                result = nextLight->steps;
                nextLight = GetNextLight(lightsToExplore, maxDistance);
                continue;
            }

            if (result > nextLight->steps) {
                result = nextLight->steps;
            }
        }

        if (nextLight->steps >= result && result != -1) {
            nextLight = GetNextLight(lightsToExplore, maxDistance);
            continue;
        }

        if (nextLight->steps > maxSteps) {
            nextLight = GetNextLight(lightsToExplore, maxDistance);
            continue;
        }

        for (auto& button : *buttons) {
            IndicatorLight* newLight = CreateNewLightWithButtonPush(nextLight, *button);
            int distacnce = DistanceBetweenLightDiagrams(newLight, final);
            if (distacnce <= maxDistance) {
                lightsToExplore[distacnce].push_back(newLight);
            }
        }

        nextLight = GetNextLight(lightsToExplore, maxDistance);
    }

    return result;
}

int Year2025Day10::DistanceBetweenLightDiagrams(IndicatorLight* light1, IndicatorLight* light2) {
    int distance = 0;
    for (int i = 0; i < light1->diagram.size(); i++) {
        distance += std::abs(light1->diagram[i] - light2->diagram[i]);
    }

    return distance;
}

IndicatorLight* Year2025Day10::GetNextLight(std::map<int, std::vector<IndicatorLight*>>& lightsToExplore, int max) {
    IndicatorLight* result = nullptr;

    for (int i = 0; i <= max; i++) {
        if (lightsToExplore[i].size() > 0) {
            std::sort(lightsToExplore[i].begin(), lightsToExplore[i].end(), [](IndicatorLight* light1, IndicatorLight* light2) {
                return light1->steps < light2->steps;
            });
            result = lightsToExplore[i][0];
            lightsToExplore[i].erase(lightsToExplore[i].begin());
            return result;
        }
    }

    return result;
}

bool Year2025Day10::VisitedBefore(IndicatorLight* light, const std::vector<IndicatorLight*>& visitedLights) {
    for (auto& visitedLight : visitedLights) {
        if (CheckIfSame(light, visitedLight)) {
            return true;
        }
    }

    return false;
}

IndicatorLight* Year2025Day10::CreateNewLightWithButtonPush(IndicatorLight* current, Button& button) {
    IndicatorLight* newLight = new IndicatorLight();
    allLights.push_back(newLight);
    for (auto d : current->diagram) {
        newLight->diagram.push_back(d);
    }

    for (auto& b : button.lights) {
        if (newLight->diagram[b] == 1) {
            newLight->diagram[b] = 0;
        }
        else {
            newLight->diagram[b] = 1;
        }
    }

    newLight->steps = current->steps+1;

    return newLight;
}

bool Year2025Day10::CheckIfSame(IndicatorLight* light, IndicatorLight* visitedLight) {
    if (light->diagram.size() != visitedLight->diagram.size()) {
        return false;
    }

    if (light->steps < visitedLight->steps) {
        return false;
    }

    for (int i = 0; i < light->diagram.size(); i++) {
        if (light->diagram[i] != visitedLight->diagram[i])
            return false;
    }

    return true;
}

IndicatorLight* Year2025Day10::CreateJoltageLight(std::string line) {
    line = line.substr(line.find('{')+1);
    line = line.substr(0, line.length()-1);

    auto parts = StringHelper::SplitString(line, ",");
    IndicatorLight* light = new IndicatorLight();

    for (auto& part : parts) {
        light->diagram.push_back(std::stoi(part));
    }

    return light;
}

std::vector<std::vector<int>*>* Year2025Day10::CreateMatrix(IndicatorLight* joltageLight, std::vector<Button*>* buttons) {
    auto matrix = new std::vector<std::vector<int>*>;
    for (int i = 0; i < joltageLight->diagram.size(); i++) {
        auto row = new std::vector<int>();
        for (auto button : *buttons) {
            if (std::find(button->lights.begin(),button->lights.end(), i) != button->lights.end()) {
                row->push_back(1);
            } else {
                row->push_back(0);
            }
        }
        row->push_back(joltageLight->diagram[i]);
        matrix->push_back(row);
    }

    return matrix;
}

void Year2025Day10::SolveMatrix(std::vector<std::vector<int>*>* matrix) {
    bool finished = false;
    while (!finished) {
        finished = true;
        GetMatrixRowsInOrder(matrix);
    }
}

void Year2025Day10::GetMatrixRowsInOrder(std::vector<std::vector<int>*>* matrix) {
    bool finished = false;
    while (!finished) {
        finished = true;
        for (int i = 1; i < matrix->size(); i++) {
            int firstOnePrevious = std::find((*matrix)[i-1]->begin(), (*matrix)[i-1]->end(), 1) - (*matrix)[i -1]->begin();
            int firstOneCurrent = std::find((*matrix)[i]->begin(), (*matrix)[i]->end(), 1) - (*matrix)[i]->begin();
            if (firstOneCurrent < firstOnePrevious) {
                finished = false;
                std::swap((*matrix)[i-1], (*matrix)[i]);
                break;
            }
        }
    }
    std::cout << "Done";
}



template <typename T>
void Year2025Day10::DeleteVectorElements(std::vector<T>& elements) {
    for (auto& element : elements) {
        delete element;
    }
    elements.clear();
}