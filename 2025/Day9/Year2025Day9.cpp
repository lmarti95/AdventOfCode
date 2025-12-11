#include "Year2025Day9.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

#include <Point.h>

void Year2025Day9::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day9::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::vector<Point*> points;

    for (auto& line : lines) {
        auto parts = StringHelper::SplitString(line, ",");
        Point* point = new Point(std::stoi(parts[0]), std::stoi(parts[1]));
        points.push_back(point);
    }


    long max = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            long xSide = std::abs(points[i]->X - points[j]->X)+1;
            long ySide = std::abs(points[i]->Y - points[j]->Y)+1;
            long area = xSide * ySide;
            max = std::max(area, max);
        }
    }

    std::cout << "Result: " << max << std::endl;

    for (auto& point : points) {
        delete point;
    }
}

void Year2025Day9::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    std::vector<Point*> points;

    for (auto& line : lines) {
        auto parts = StringHelper::SplitString(line, ",");
        Point* point = new Point(std::stoi(parts[0]), std::stoi(parts[1]));
        points.push_back(point);
    }

    std::vector<std::vector<char>> tiles;
    SetUpTiles(tiles, points);

    std::cout << "Setup done" << std::endl;

    int previousX = points[points.size()-1]->X;
    int previousY = points[points.size()-1]->Y;
    for (auto& point : points) {
        if (point->X == previousX) {
            int startY = std::min(previousY, point->Y)+1;
            int endY = std::max(previousY, point->Y);
            for (int i = startY; i < endY; i++) {
                tiles[i][previousX] = 'Y';
            }
        }
        else {
            int startX = std::min(previousX, point->X)+1;
            int endX = std::max(previousX, point->X);
            for (int i = startX; i < endX; i++) {
                tiles[previousY][i] = 'Y';
            }
        }
        previousX = point->X;
        previousY = point->Y;
    }

    std::cout << "Walls done" << std::endl;


    for (int i = 0; i < tiles.size(); i++) {
        bool inside = false;
        for (int j = 0; j < tiles[0].size(); j++) {
            if (inside && tiles[i][j] == '.') {
                tiles[i][j] = 'X';
            }
            if (tiles[i][j] == 'Y') {
                inside = !inside;
            }
            if (tiles[i][j] == '#') {
                break;
            }
        }
    }

    for (int i = 0; i < tiles.size(); i++) {
        bool inside = false;
        for (int j = tiles[0].size()-1; j >= 0 ; j--) {
            if (inside && tiles[i][j] == '.') {
                tiles[i][j] = 'X';
            }
            if (tiles[i][j] == 'Y') {
                inside = !inside;
            }
            if (tiles[i][j] == '#') {
                break;
            }
        }
    }

    for (int j = 0; j < tiles[0].size(); j++) {
        bool inside = false;
        for (int i = 0; i < tiles.size(); i++) {
            if (inside && tiles[i][j] == '.') {
                tiles[i][j] = 'X';
            }
            if (tiles[i][j] == 'Y') {
                inside = !inside;
            }
            if (tiles[i][j] == '#') {
                break;
            }
        }
    }

    for (int j = 0; j < tiles[0].size(); j++) {
        bool inside = false;
        for (int i = tiles.size()-1; i >= 0 ; i--) {
            if (inside && tiles[i][j] == '.') {
                tiles[i][j] = 'X';
            }
            if (tiles[i][j] == 'Y') {
                inside = !inside;
            }
            if (tiles[i][j] == '#') {
                break;
            }
        }
    }

    std::cout << "Inside done" << std::endl;

    long long maxArea = 0;
    for (int i = 0; i < points.size(); i++) {
        std::cout << "Calculating sizes from point number" << i << std::endl;
        for (int j = i+1; j < points.size(); j++) {
            int startX = std::min(points[i]->X ,points[j]->X);
            int endX = std::max(points[i]->X ,points[j]->X)+1;
            int startY = std::min(points[i]->Y ,points[j]->Y);
            int endY = std::max(points[i]->Y ,points[j]->Y)+1;
            bool valid = true;
            for (int k = startY; k < endY; k++) {
                if (!valid) {
                    break;
                }
                for (int l = startX; l < endX; l++) {
                    if (tiles[k][l] == '.') {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                long long xSide = std::abs(points[i]->X - points[j]->X)+1;
                long long ySide = std::abs(points[i]->Y - points[j]->Y)+1;
                long long area = xSide * ySide;
                maxArea = std::max(area, maxArea);
            }
        }
    }

    //PrintTiles(tiles);

    std::cout << "Result: " << maxArea << std::endl;

    for (auto& point : points) {
        delete point;
    }
}

void Year2025Day9::SetUpTiles(std::vector<std::vector<char>>& tiles, std::vector<Point*>& points) {
    int maxX = 0;
    int maxY = 0;
    for (auto& point : points) {
        maxX = std::max(maxX, point->X);
        maxY = std::max(maxY, point->Y);
    }

    maxX+=2;
    maxY+=2;

    for (int i = 0; i < maxY; i++) {
        std::vector<char> temp;
        for (int j = 0; j < maxX; j++) {
            temp.push_back('.');
        }
        tiles.push_back(temp);
    }

    for (auto& point : points) {
        tiles[point->Y][point->X] = '#';
    }
}

void Year2025Day9::PrintTiles(std::vector<std::vector<char>> &tiles) {
    for (int i = 0; i < tiles.size(); i++) {
        for (int j =0; j < tiles[i].size(); j++) {
            std::cout << tiles[i][j];
        }
        std::cout << std::endl;
    }
}