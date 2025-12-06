#include "Range.h"

Range::Range(std::string word) {
    LowerBound = std::stoll(word.substr(0,word.find('-')));
    UpperBound = stoll(word.substr(word.find('-')+1));
}

bool Range::InRange(long long number) {
    return number >= LowerBound && number <= UpperBound;
}

bool Range::CanBeMerged(Range& range) {
    if (!range.Valid || !Valid) {
        return false;
    }

    if (range.LowerBound <= UpperBound && range.LowerBound >= LowerBound) {
        return true;
    }

    if (range.UpperBound <= UpperBound && range.UpperBound >= LowerBound) {
        return true;
    }

    if (range.LowerBound <= LowerBound && range.UpperBound >= UpperBound) {
        return true;
    }

    return false;
}

void Range::Merge(Range& range) {
    range.Valid = false;

    LowerBound = std::min(LowerBound, range.LowerBound);
    UpperBound = std::max(UpperBound, range.UpperBound);
}