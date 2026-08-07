#include "Year2015Day6.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

void Year2015Day6::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

enum class Commands { TOGGLE, ON, OFF};

struct Area {
    int fromX;
    int fromY;
    int toX;
    int toY;
};

Commands GetCommand(const std::string& line);
Area GetArea(const std::string& line);
void SetLights(Commands command, Area area, std::vector<std::vector<bool>>& decoration);
void SetLights(Commands command, Area area, std::vector<std::vector<long>>& decoration);
int GetNumberOfTurnedOnLights(std::vector<std::vector<bool>>& decoration);
long GetNumberOfTurnedOnLights(std::vector<std::vector<long>>& decoration);

void Year2015Day6::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::vector<std::vector<bool>> decoration;

    for (int i = 0; i < 1000; i++) {
        std::vector<bool> temp;
        temp.reserve(1000);
        for (int j = 0; j < 1000; j++) {
            temp.emplace_back(false);
        }
        decoration.push_back(temp);
    }

    for (auto& line : lines) {
        SetLights(GetCommand(line), GetArea(line), decoration);
    }

    std::cout << "Result: " << GetNumberOfTurnedOnLights(decoration) << std::endl;
}

void Year2015Day6::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    std::vector<std::vector<long>> decoration;

    for (int i = 0; i < 1000; i++) {
        std::vector<long> temp;
        temp.reserve(1000);
        for (int j = 0; j < 1000; j++) {
            temp.emplace_back(0l);
        }
        decoration.push_back(temp);
    }

    for (auto& line : lines) {
        SetLights(GetCommand(line), GetArea(line), decoration);
    }

    std::cout << "Result: " << GetNumberOfTurnedOnLights(decoration) << std::endl;
}

Commands GetCommand(const std::string& line) {
    if (line.substr(0, 6) == "toggle") {
        return Commands::TOGGLE;
    }

    if (line.substr(5, 2) == "on") {
        return  Commands::ON;
    }

    return Commands::OFF;
}

Area GetArea(const std::string& line) {
    Area area;

    std::vector<std::string> parts = StringHelper::SplitString(line, " ");
    std::vector<std::string> FirstNumberPair = StringHelper::SplitString(parts[parts.size()-3],",");
    std::vector<std::string> SecondNumberPair = StringHelper::SplitString(parts[parts.size()-1],",");
    area.fromX = std::stoi(FirstNumberPair[0]);
    area.fromY = std::stoi(FirstNumberPair[1]);
    area.toX = std::stoi(SecondNumberPair[0]);
    area.toY = std::stoi(SecondNumberPair[1]);

    return  area;
}

void SetLights(Commands command, Area area, std::vector<std::vector<bool>>& decoration) {
    for (int i = area.fromX; i <= area.toX; i++) {
        for (int j = area.fromY; j <= area.toY; j++) {
            if ( command == Commands::OFF) {
                decoration[i][j] = false;
            }
            if ( command == Commands::ON) {
                decoration[i][j] = true;
            }
            if ( command == Commands::TOGGLE) {
                decoration[i][j] = !decoration[i][j];
            }
        }
    }
}

void SetLights(Commands command, Area area, std::vector<std::vector<long>>& decoration) {
    for (int i = area.fromX; i <= area.toX; i++) {
        for (int j = area.fromY; j <= area.toY; j++) {
            if ( command == Commands::OFF) {
                decoration[i][j]--;
                decoration[i][j] = std::max(0l, decoration[i][j]);
            }
            if ( command == Commands::ON) {
                decoration[i][j]++;
            }
            if ( command == Commands::TOGGLE) {
                decoration[i][j]++;
                decoration[i][j]++;
            }
        }
    }
}

int GetNumberOfTurnedOnLights(std::vector<std::vector<bool>>& decoration) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (decoration[i][j]) {
                count++;
            }
        }
    }

    return count;
}

long GetNumberOfTurnedOnLights(std::vector<std::vector<long>>& decoration) {
    long count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            count+= decoration[i][j];
        }
    }

    return count;
}