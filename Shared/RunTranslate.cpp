//
// Created by Marton Leitold on 01/12/2025.
//

#include "RunTranslate.h"

#include "../2025/Day1/Year2025Day1.h"
#include "../2025/Day2/Year2025Day2.h"
#include "../2025/Day3/Year2025Day3.h"
#include "../2025/Day4/Year2025Day4.h"

void RunTranslate::RunCorrectFunction(int year, int day, int inputType) {
    switch (year) {
        case 2025:
            RunCorrectday2025(day, CreatePath(year, day, inputType));
            break;
        default:
            return;
    }


}

void RunTranslate::RunCorrectday2025(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2025Day1::Run(filenamePath);
            break;
        case 2:
            Year2025Day2::Run(filenamePath);
            break;
        case 3:
            Year2025Day3::Run(filenamePath);
            break;
        case 4:
            Year2025Day4::Run(filenamePath);
            break;
        default:
            break;
    }
}

std::string RunTranslate::CreatePath(int year, int day, int inputType) {
    std::string path = "../" + std::to_string(year) +"/Day" + std::to_string(day)+"/";
    if (inputType == 0) {
        path+="small.txt";
    } else if (inputType == 1) {
        path+="real.txt";
    }

    return path;
}
