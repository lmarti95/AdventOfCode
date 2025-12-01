//
// Created by Marton Leitold on 01/12/2025.
//

#include "Menu.h"
#include "RunTranslate.h"

#include <iostream>

int year = 2025;

void Menu::RunMenu() {
    int day;
    int input;
    std::cout << "What day to solve for?" << std::endl;
    std::cin >> day;
    std::cout << "Small(0) or Real(1) input?" << std::endl;
    std::cin >> input;
    RunTranslate::RunCorrectFunction(year,day,input);
}
