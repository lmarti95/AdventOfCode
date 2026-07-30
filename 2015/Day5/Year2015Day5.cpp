#include "Year2015Day5.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>
#include <map>

void Year2015Day5::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

bool ContainsInvalidCharacterPairs(std::string line);
bool ContainsThreeVowels(std::string line);
bool ContainsDuplicateLetters(std::string line);

bool ContainsPair(std::string line);
bool ContainsLetterRepeat(std::string line);

void Year2015Day5::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    for (auto line : lines)
    {
        if (!ContainsInvalidCharacterPairs(line) && ContainsThreeVowels(line) && ContainsDuplicateLetters(line))
        {
            result++;
        }
    }

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day5::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    int result = 0;

    for (auto line : lines)
    {
        if (ContainsPair(line) && ContainsLetterRepeat(line))
        {
            result++;
        }
    }

    std::cout << "Result: " << result << std::endl;
}

bool ContainsInvalidCharacterPairs(std::string line)
{
    for (int i = 1; i < line.length(); i++)
    {
        if (line[i-1] == 'a' && line[i] == 'b')
        {
            return true;
        }
        if (line[i-1] == 'c' && line[i] == 'd')
        {
            return true;
        }
        if (line[i-1] == 'p' && line[i] == 'q')
        {
            return true;
        }
        if (line[i-1] == 'x' && line[i] == 'y')
        {
            return true;
        }
    }
    return false;
}

bool ContainsThreeVowels(std::string line)
{
    int counter = 0;
    for (auto c : line)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            counter ++;
        }
    }
    return counter > 2;
}

bool ContainsDuplicateLetters(std::string line)
{
    for (int i = 1; i < line.length(); i++)
    {
        if (line[i-1] == line[i])
        {
            return true;
        }
    }

    return false;
}

bool ContainsPair(std::string line)
{
    std::map<std::string, int> pairs;

    for (int i = 0; i < line.length()-1; i++)
    {
        if (pairs.find(line.substr(i, 2)) == pairs.end())
        {
            pairs[line.substr(i, 2)] = i;
        }
        else
        {
           if (pairs[line.substr(i, 2)] < i - 1)
           {
               return true;
           }
        }
    }

    return false;
}

bool ContainsLetterRepeat(std::string line)
{
    for (int i = 2; i < line.length(); i++)
    {
        if (line[i-2] == line[i])
        {
            return true;
        }
    }

    return false;
}