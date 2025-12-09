#include "Year2025Day8.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <Point.h>

#include <iostream>
#include <map>

void Year2025Day8::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day8::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::vector<Point*> points;

    for (int i = 0; i < lines.size(); i++) {
        auto parts = StringHelper::SplitString(lines[i],",");
        Point* point = new Point(parts[0], parts[1], parts[2], i);
        points.push_back(point);
    }

    std::vector<std::tuple<double, Point*, Point*>> distances;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            distances.push_back(std::make_tuple(points[i]->GetDistance(points[j]),points[i],points[j]));
        }
    }

    std::sort(distances.begin(), distances.end(), [](std::tuple<double, Point*, Point*> a, std::tuple<double, Point*, Point*> b) {
        return std::get<0>(a) < std::get<0>(b);
    });

    int i = 0;
    std::vector<std::vector<Point*>> circuits;
    while (i < 1000) {
        if ( i >= distances.size()) {
            break;
        }
        Point* p1 =std::get<1>(distances[i]);
        Point* p2 = std::get<2>(distances[i]);
        if (!p1->partOfCircuit || !p2->partOfCircuit) {
            if (!p1->partOfCircuit && !p2->partOfCircuit) {
                std::vector<Point*> tempCircuit;
                tempCircuit.push_back(p1);
                tempCircuit.push_back(p2);
                circuits.push_back(tempCircuit);
                p1->partOfCircuit = true;
                p2->partOfCircuit = true;
                p1->circuit = circuits.size() -1;
                p2->circuit = circuits.size() -1;
            }
            else {
                if (p1->partOfCircuit) {
                    circuits[p1->circuit].push_back(p2);
                    p2->circuit = p1->circuit;
                    p2->partOfCircuit = true;
                } else {
                    circuits[p2->circuit].push_back(p1);
                    p1->circuit = p2->circuit;
                    p1->partOfCircuit = true;
                }
            }
        }
        else {
            if (p1->circuit != p2->circuit) {
                std::vector<Point*> mergedPoints;
                int toBeCleared1 = p1->circuit;
                int toBeCleared2 = p2->circuit;
                for (auto& point : circuits[p1->circuit]) {
                    point->circuit = circuits.size();
                    mergedPoints.push_back(point);
                }
                for (auto& point : circuits[p2->circuit]) {
                    point->circuit = circuits.size();
                    mergedPoints.push_back(point);
                }

                circuits[toBeCleared1].clear();
                circuits[toBeCleared2].clear();

                circuits.push_back(mergedPoints);
            }
        }
        i++;
    }

    std::sort(circuits.begin(), circuits.end(), [](std::vector<Point*> a, std::vector<Point*> b) {
        return a.size() > b.size();
    });

    long long result = circuits[0].size()*circuits[1].size()*circuits[2].size();

    std::cout << "Result: " << result << std::endl;

    for (auto& point : points) {
        delete point;
    }
}

void Year2025Day8::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::vector<Point*> points;

    for (int i = 0; i < lines.size(); i++) {
        auto parts = StringHelper::SplitString(lines[i],",");
        Point* point = new Point(parts[0], parts[1], parts[2], i);
        points.push_back(point);
    }

    std::vector<std::tuple<double, Point*, Point*>> distances;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            distances.push_back(std::make_tuple(points[i]->GetDistance(points[j]),points[i],points[j]));
        }
    }

    std::sort(distances.begin(), distances.end(), [](std::tuple<double, Point*, Point*> a, std::tuple<double, Point*, Point*> b) {
        return std::get<0>(a) < std::get<0>(b);
    });

    int i = 0;
    int lastX1;
    int lastX2;
    std::vector<std::vector<Point*>> circuits;
    while (!IsAllConnecred(circuits, points.size())) {
        if ( i >= distances.size()) {
            break;
        }
        Point* p1 =std::get<1>(distances[i]);
        Point* p2 = std::get<2>(distances[i]);
        lastX1 = p1->X;
        lastX2 = p2->X;
        if (!p1->partOfCircuit || !p2->partOfCircuit) {
            if (!p1->partOfCircuit && !p2->partOfCircuit) {
                std::vector<Point*> tempCircuit;
                tempCircuit.push_back(p1);
                tempCircuit.push_back(p2);
                circuits.push_back(tempCircuit);
                p1->partOfCircuit = true;
                p2->partOfCircuit = true;
                p1->circuit = circuits.size() -1;
                p2->circuit = circuits.size() -1;
            }
            else {
                if (p1->partOfCircuit) {
                    circuits[p1->circuit].push_back(p2);
                    p2->circuit = p1->circuit;
                    p2->partOfCircuit = true;
                } else {
                    circuits[p2->circuit].push_back(p1);
                    p1->circuit = p2->circuit;
                    p1->partOfCircuit = true;
                }
            }
        }
        else {
            if (p1->circuit != p2->circuit) {
                std::vector<Point*> mergedPoints;
                int toBeCleared1 = p1->circuit;
                int toBeCleared2 = p2->circuit;
                for (auto& point : circuits[p1->circuit]) {
                    point->circuit = circuits.size();
                    mergedPoints.push_back(point);
                }
                for (auto& point : circuits[p2->circuit]) {
                    point->circuit = circuits.size();
                    mergedPoints.push_back(point);
                }

                circuits[toBeCleared1].clear();
                circuits[toBeCleared2].clear();

                circuits.push_back(mergedPoints);
            }
        }
        i++;
    }

    long long result = (long)lastX1 * (long)lastX2;

    std::cout << "Result: " << result << std::endl;

    for (auto& point : points) {
        delete point;
    }
}

bool Year2025Day8::IsAllConnecred(std::vector<std::vector<Point*>>& circuits, int size) {
    int maxCircuit = 0;
    for (auto& circuit : circuits) {
        maxCircuit = std::max(maxCircuit, (int)circuit.size());
    }
    return maxCircuit == size;
}