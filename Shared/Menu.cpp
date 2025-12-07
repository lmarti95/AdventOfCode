//
// Created by Marton Leitold on 01/12/2025.
//

#include "Menu.h"
#include "RunTranslate.h"

#include <iostream>
#include <fstream>

int year = 2025;

void Menu::RunMenu() {
    TryToReadLastInput();
    std::string year;
    std::string day;
    std::string inputType;
    std::cout << "What year to solve for? (Default: " << (DefaultYear == 0 ? "2025" : std::to_string(DefaultYear))  << ")" << std::endl;
    std::cin >> year;
    year = year == "" ? std::to_string(DefaultYear) : year;
    std::cout << "What day to solve for? (Default: " << (DefaultDay == 0 ? "1" : std::to_string(DefaultDay))  << ")" << std::endl;
    std::cin >> day;
    day = day == "" ? std::to_string(DefaultDay) : day;
    std::cout << "Small(0) or Real(1) input? (Default: " << DefaultInputType  << ")" << std::endl;
    std::cin >> inputType;
    inputType = inputType == "" ? std::to_string(DefaultInputType) : inputType;
    SaveLatestInput(year, day, inputType);
    RunTranslate::RunCorrectFunction(std::stoi(year),std::stoi(day),std::stoi(inputType));
}

void Menu::TryToReadLastInput() {
    std::ifstream file("defaults.txt");
    std::string line;
    if (file.is_open()) {
        std::getline(file,line);
        Menu::DefaultYear = std::stoi(line);
        std::getline(file,line);
        Menu::DefaultDay = std::stoi(line);
        std::getline(file,line);
        Menu::DefaultInputType = std::stoi(line);
    }
}

void Menu::SaveLatestInput(std::string year, std::string day, std::string inputType) {
    std::ofstream file;
    file.open("defaults.txt");
    file << year << std::endl;
    file << day << std::endl;
    file << inputType << std::endl;
    file.close();
}
