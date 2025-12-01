//
// Created by Marton Leitold on 30/11/2025.
//

#include "ReadHelper.h"

#include <fstream>
#include <iostream>

std::vector<std::string> ReadHelper::ReadLines(std::string path) {
    std::vector<std::string> result;
    std::cout << path << std::endl;

    std::ifstream file(path);

    std::string line;
    while (std::getline(file, line))
    {
       result.push_back(line);
    }

    return result;
}