#include "Year2025Day7.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

#include "Point.h"

void Year2025Day7::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day7::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    StringHelper::ChangePartsOfString(lines[0],"S", "|");

    for (int i = 1; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] == '.' && lines[i-1][j] == '|') {
                lines[i][j] = '|';
                continue;
            }
            if (lines[i][j] == '^' && lines[i-1][j] == '|') {
                result++;
                if (j != 0 && lines[i][j-1] == '.') {
                    lines[i][j-1] = '|';
                }
                if (j <lines.size()-1 && lines[i][j+1] == '.') {
                    lines[i][j+1] = '|';
                }
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day7::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    long long result = 0;

    std::vector<std::vector<Point>> points;

    for (int i = 0; i < lines.size(); i++) {
        std::vector<Point> linePoints;
        for (int j = 0; j < lines[i].size(); j++) {
            Point p;
            if (lines[i][j] == '^') {
                p.Splitter = true;
            }
            if (lines[i][j] == 'S') {
                p.BeamCount = 1;
            }
            linePoints.push_back(p);
        }
        points.push_back(linePoints);
    }

    for (int i = 1; i < points.size(); i++) {
        for (int j = 0; j < points[i].size(); j++) {
            if (!points[i][j].Splitter && points[i-1][j].BeamCount > 0) {
                points[i][j].BeamCount += points[i-1][j].BeamCount;
                continue;
            }
            if (points[i][j].Splitter && points[i-1][j].BeamCount > 0) {
                if (j != 0) {
                    points[i][j-1].BeamCount+=points[i-1][j].BeamCount;
                }
                if (j <lines.size()-1) {
                    points[i][j+1].BeamCount+=points[i-1][j].BeamCount;
                }
            }
        }
    }

    for (auto& point : points[points.size()-1]) {
        result += point.BeamCount;
    }

    std::cout << "Result: " << result << std::endl;
}
