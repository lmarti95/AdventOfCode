#include "Year2015Day11.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

bool CheckFirstRequirement(const std::string& inputWord);
bool CheckThirdRequirement(const std::string& inputWord);
void GetNextCombination(std::string& word);

void Year2015Day11::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day11::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::string word = lines[0];

    while (!CheckFirstRequirement(word) || !CheckThirdRequirement(word)) {
        GetNextCombination(word);
    }

    std::cout << "Result: " << word << std::endl;
}

void Year2015Day11::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    std::string word = lines[0];
    GetNextCombination(word);

    while (!CheckFirstRequirement(word) || !CheckThirdRequirement(word)) {
        GetNextCombination(word);
    }

    GetNextCombination(word);

    while (!CheckFirstRequirement(word) || !CheckThirdRequirement(word)) {
        GetNextCombination(word);
    }

    std::cout << "Result: " << word << std::endl;
}

void GetNextCombination(std::string& word) {
    bool carry = false;
    for (int i = word.length()-1; i != 0; i--) {
        if (i == word.length()-1) {
            if (word[i] == 'z') {
                word[i] = 'a';
                carry = true;
                continue;
            }
            else {
                word[i]++;
            }
        }

        if (carry) {
            if (word[i] == 'z') {
                word[i] = 'a';
                carry = true;
            }
            else {
                word[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'i' || word[i] == 'l' ||  word[i] == 'o') {
            word[i]++;
            for (int j = i+1; j < word.length(); j++) {
                word[j] = 'a';
            }
        }
    }

    if (word[word.length()-1] == 'i'
        || word[word.length()-1] == 'l'
        || word[word.length()-1] == 'o') {
        word[word.length()-1]++;
    }

}

bool CheckFirstRequirement(const std::string& inputWord) {
    for (int i = 0; i < inputWord.length()-2; i++) {
        if (inputWord[i] == inputWord[i+1]-1 &&  inputWord[i] == inputWord[i+2] -2) {
            return true;
        }
    }

    return false;
}

bool CheckThirdRequirement(const std::string& inputWord) {
    int count = 0;
    for (int i = 0; i < inputWord.length()-1; i++) {
        if (inputWord[i] == inputWord[i+1]) {
            count++;
            i++;
        }
    }

    return count > 1;
}
