#ifndef ADVENTOFCODE_RANGE_H
#define ADVENTOFCODE_RANGE_H

#include <string>

class Range {
public:
    Range(std::string);
    bool InRange(long long number);
    bool CanBeMerged(Range& range);
    void Merge(Range& range);

    long long LowerBound;
    long long UpperBound;
    bool Valid = true;
};


#endif //ADVENTOFCODE_RANGE_H