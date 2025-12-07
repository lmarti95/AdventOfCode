//
// Created by Marton Leitold on 01/12/2025.
//

#ifndef ADVENTOFCODE_MENU_H
#define ADVENTOFCODE_MENU_H

#include <string>

class Menu {
public:
    void RunMenu();
private:
    void TryToReadLastInput();
    void SaveLatestInput(std::string year, std::string day, std::string inputType);
    int DefaultYear = 0;
    int DefaultDay = 0;
    int DefaultInputType = 0;
};


#endif //ADVENTOFCODE_MENU_H