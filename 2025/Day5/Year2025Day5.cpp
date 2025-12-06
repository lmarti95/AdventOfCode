#include "Year2025Day5.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"
#include "Range.h"

#include <iostream>

void Year2025Day5::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2025Day5::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    std::vector<Range> ranges;

    for (auto& line : lines) {
        if (line.find('-') != std::string::npos) {
            ranges.emplace_back(line);
            continue;
        }
        if (line.empty()) {
            continue;
        }

        long long number = stoll(line);
        for (auto& range : ranges) {
            if (range.InRange(number)) {
                result++;
                break;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2025Day5::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    long long result = 0;

    std::vector<Range> ranges;

    for (auto& line : lines) {
        if (line.find('-') != std::string::npos) {
            ranges.emplace_back(line);
            continue;
        }
    }

    bool mergeWasFound = true;
    while (mergeWasFound) {
        mergeWasFound = false;
        for (int i = 0; i < ranges.size();i++) {
            for (int j = i+1; j < ranges.size(); j++) {
                if (ranges[i].CanBeMerged(ranges[j])) {
                    ranges[i].Merge(ranges[j]);
                    mergeWasFound = true;
                }
            }
        }
    }

    for (auto& range : ranges) {
        if (range.Valid) {
            result += range.UpperBound - range.LowerBound+1;
        }
    }

    std::cout << "Result: " << result << std::endl;
}
