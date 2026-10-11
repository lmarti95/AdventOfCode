#include "Year2015Day9.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>
#include <set>
#include <map>

class Distance {
public:
    std::string city1;
    std::string city2;
    int value;
};

std::vector<Distance> distances;

Distance CreateDistance(std::string line);
bool Connected(const std::set<int>& selectedDistances, int maxCities);
bool CityEdgeCountIsCorrect(const std::set<int>& selectedDistances);

void Year2015Day9::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day9::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::set<std::string> cities;
    for (auto& line : lines) {
        distances.push_back(CreateDistance(line));
        cities.emplace(distances[distances.size()-1].city1);
        cities.emplace(distances[distances.size()-1].city2);
    }

    int maxCities = cities.size();

    std::vector<bool> selectedDistances;

    for (int i = selectedDistances.size(); i < distances.size(); i++) {
        selectedDistances.push_back(false);
    }

    for (int i = 0; i < maxCities-1; i++) {
        selectedDistances.push_back(true);
    }

    int result = INT_MAX;

    do {
        int tempResult = 0;
        std::set<int> selectedDistancesSet;
        for (int i = 0; i < selectedDistances.size(); i++) {
            if (selectedDistances[i]) {
                selectedDistancesSet.emplace(i);
            }
        }

        if (!Connected(selectedDistancesSet, maxCities)
            || !CityEdgeCountIsCorrect(selectedDistancesSet)) {
            continue;
        }

        for (int i = 0; i < selectedDistances.size(); i++) {
            if (selectedDistances[i]) {
                tempResult += distances[i].value;
            }
        }
        result = std::min(result, tempResult);
    } while (std::next_permutation(selectedDistances.begin(), selectedDistances.end()));

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day9::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    distances.clear();
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::set<std::string> cities;
    for (auto& line : lines) {
        distances.push_back(CreateDistance(line));
        cities.emplace(distances[distances.size()-1].city1);
        cities.emplace(distances[distances.size()-1].city2);
    }

    int maxCities = cities.size();

    std::vector<bool> selectedDistances;

    for (int i = selectedDistances.size(); i < distances.size(); i++) {
        selectedDistances.push_back(false);
    }

    for (int i = 0; i < maxCities-1; i++) {
        selectedDistances.push_back(true);
    }

    int result = 0;

    do {
        int tempResult = 0;
        std::set<int> selectedDistancesSet;
        for (int i = 0; i < selectedDistances.size(); i++) {
            if (selectedDistances[i]) {
                selectedDistancesSet.emplace(i);
            }
        }

        if (!Connected(selectedDistancesSet, maxCities)
            || !CityEdgeCountIsCorrect(selectedDistancesSet)) {
            continue;
            }

        for (int i = 0; i < selectedDistances.size(); i++) {
            if (selectedDistances[i]) {
                tempResult += distances[i].value;
            }
        }
        result = std::max(result, tempResult);
    } while (std::next_permutation(selectedDistances.begin(), selectedDistances.end()));


    std::cout << "Result: " << result << std::endl;
}

Distance CreateDistance(std::string line) {
    Distance distance;
    distance.city1 = line.substr(0, line.find(" "));
    distance.city2 = line.substr(line.find(" ")+4, line.find('=')-5-line.find(" "));
    distance.value = std::stoi(line.substr(line.find("=")+2));

    return distance;
}

void DiscoverCities(const std::set<int>& selectedDistances, std::set<std::string>& cities,
    std::set<int>& discoveredEdges, std::vector<int>& toBeDiscoveredEdges) {
    if (toBeDiscoveredEdges.empty()) {
        return;
    }
    std::string currentCity1 = distances[toBeDiscoveredEdges[0]].city1;
    std::string currentCity2 = distances[toBeDiscoveredEdges[0]].city2;

    cities.emplace(currentCity1);
    cities.emplace(currentCity2);

    for (int i = 0; i < distances.size(); i++) {
        if (selectedDistances.contains(i)
            && !discoveredEdges.contains(i)
            && (distances[i].city1 == currentCity1 || distances[i].city1 == currentCity2
                || distances[i].city2 == currentCity1 || distances[i].city2 == currentCity2)) {
            toBeDiscoveredEdges.push_back(i);
                }
    }

    discoveredEdges.emplace(toBeDiscoveredEdges[0]);
    toBeDiscoveredEdges.erase(toBeDiscoveredEdges.begin());

    return DiscoverCities(selectedDistances, cities, discoveredEdges, toBeDiscoveredEdges);
}

bool Connected(const std::set<int>& selectedDistances, int maxCities) {
    if (selectedDistances.empty()) {
        return false;
    }

    std::set<std::string> cities;
    std::set<int> discoveredEdges;

    std::vector<int> toBeDiscoveredEdges;
    toBeDiscoveredEdges.push_back(*selectedDistances.begin());

    DiscoverCities(selectedDistances, cities, discoveredEdges, toBeDiscoveredEdges);

    return cities.size() == maxCities;
}

bool CityEdgeCountIsCorrect(const std::set<int>& selectedDistances) {
    std::map<std::string, int> cityEdgesCount;
    for (auto& selectedDistance : selectedDistances) {
        cityEdgesCount[distances[selectedDistance].city1]++;
        cityEdgesCount[distances[selectedDistance].city2]++;
    }

    for (auto& count : cityEdgesCount) {
        if (count.second > 2) {
            return false;
        }
    }

    return true;
}