#include "Year2015Day12.h"
#include "../../Shared/ReadHelper.h"
#include "../../Shared/StringHelper.h"

#include <iostream>

 enum Type {Array, Object};

struct Element {
    Type type;
    Element* parent = nullptr;
    std::vector<Element*> children;
    int count = 0;
    bool isBlocked = false;
};

int Process(std::string& json);
void Process2(std::string& json);

int Calculate(Element* element);
void Delete(Element* element);

Element* root;

void Year2015Day12::Run(std::string filenamePath) {
    RunPart1(filenamePath);
    RunPart2(filenamePath);
}

void Year2015Day12::RunPart1(std::string filenamePath) {
    std::cout << "Part 1" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);

    int result = Process(lines[0]);

    std::cout << "Result: " << result << std::endl;
}

void Year2015Day12::RunPart2(std::string filenamePath) {
    std::cout << std::endl << "Part 2" << std::endl;
    auto lines = ReadHelper::ReadLines(filenamePath);
    root = new Element();

    Process2(lines[0]);

    int result = Calculate(root);

    Delete(root);

    std::cout << "Result: " << result << std::endl;
}

int Process(std::string& json) {
    int count = 0;

    int temp = 0;
    bool minus = false;

    for (auto c : json) {
        if (c == '-') {
            temp = 0;
            minus = true;
            continue;
        }
        if (c >= '0' && c <= '9') {
            if ( temp == 0) {
                temp = c - '0';
                 continue;
            }
            temp = temp * 10 + (c - '0');
            continue;
        }

        if (temp > 0) {
            if (minus) {
                temp *= -1;
            }
            count+= temp;
        }

        temp = 0;
        minus = false;
    }

    return count;
}

void Process2(std::string& json) {

    Element* currentElement = root;

    int temp = 0;
    int minus = false;
    bool calculating = false;

    for (int i = 0; i < json.length(); i++) {
        char c = json[i];

        if (c == '-') {
            temp = 0;
            minus = true;
            continue;
        }

        if (c >= '0' && c <= '9') {
            calculating = true;
            if ( temp == 0) {
                temp = c - '0';
                continue;
            }
            temp = temp * 10 + (c - '0');
            continue;
        }

        if (calculating) {
            if (minus) {
                temp *= -1;
            }
            currentElement->count += temp;
            temp = 0;
            calculating = false;
            minus = false;
        }

        if (c == '{' || c == '[') {
            Element* element = new Element{};
            element->parent = currentElement;
            element->type = c == '{' ? Type::Object : Type::Array;
            currentElement->children.push_back(element);
            currentElement = element;
        }

        if (c == '}' || c == ']') {
            currentElement = currentElement->parent;
        }

        if (c == 'r' && json[i+1] == 'e' && json[i+2] == 'd') {
            currentElement->isBlocked = currentElement->type == Type::Object;
        }
    }
}

int Calculate(Element *element) {
    if (element->isBlocked) {
        return 0;
    }

    int count = 0;
    for (auto childElement : element->children) {
        count += Calculate(childElement);
    }

    return count += element->count;
}

void Delete(Element* element) {

    if (element->children.empty()) {
        delete element;
        return;
    }

    for (auto childElement : element->children) {
        Delete(childElement);
    }

    delete element;
}
