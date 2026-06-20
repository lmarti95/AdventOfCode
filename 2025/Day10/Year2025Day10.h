#ifndef ADVENTOFCODE_YEAR2025DAY10_H
#define ADVENTOFCODE_YEAR2025DAY10_H

#include <map>
#include <stack>
#include <string>
#include <vector>

#include "Button.h"
#include "IndicatorLight.h"

class Year2025Day10 {
public:
    static void Run(std::string filenamePath);
private:
    static void RunPart1(std::string filenamePath);
    static void RunPart2(std::string filenamePath);

    static IndicatorLight* CreateIndicatorLight(std::string line);
    static std::vector<Button*>* CreateButtons(std::string line);
    static int StepsUntilLight(IndicatorLight* final, std::vector<Button*>* buttons);
    static int DistanceBetweenLightDiagrams(IndicatorLight* light1, IndicatorLight* light2);
    static IndicatorLight* GetNextLight(std::map<int, std::vector<IndicatorLight*>>& lightsToExplore, int max);
    static bool VisitedBefore(IndicatorLight* light, const std::vector<IndicatorLight*>& visitedLights);
    static IndicatorLight* CreateNewLightWithButtonPush(IndicatorLight* current, Button& button);
    static bool CheckIfSame(IndicatorLight* light, IndicatorLight* visitedLight);

    static IndicatorLight* CreateJoltageLight(std::string line);
    static std::vector<std::vector<int>*>* CreateMatrix(IndicatorLight* joltageLight, std::vector<Button*>* buttons);
    static void SolveMatrix(std::vector<std::vector<int>*>* matrix);
    static void GetMatrixRowsInOrder(std::vector<std::vector<int>*>* matrix);


    template <typename T>
    static void DeleteVectorElements(std::vector<T>& elements);
};


#endif //ADVENTOFCODE_YEAR2025DAY10_H
