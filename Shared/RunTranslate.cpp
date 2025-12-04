//
// Created by Marton Leitold on 01/12/2025.
//

#include "RunTranslate.h"

#include "../2015/Day1/Year2015Day1.h"
#include "../2015/Day2/Year2015Day2.h"
#include "../2015/Day3/Year2015Day3.h"
#include "../2015/Day4/Year2015Day4.h"
#include "../2015/Day5/Year2015Day5.h"
#include "../2015/Day6/Year2015Day6.h"
#include "../2015/Day7/Year2015Day7.h"
#include "../2015/Day8/Year2015Day8.h"
#include "../2015/Day9/Year2015Day9.h"
#include "../2015/Day10/Year2015Day10.h"
#include "../2015/Day11/Year2015Day11.h"
#include "../2015/Day12/Year2015Day12.h"
#include "../2015/Day13/Year2015Day13.h"
#include "../2015/Day14/Year2015Day14.h"
#include "../2015/Day15/Year2015Day15.h"
#include "../2015/Day16/Year2015Day16.h"
#include "../2015/Day17/Year2015Day17.h"
#include "../2015/Day18/Year2015Day18.h"
#include "../2015/Day19/Year2015Day19.h"
#include "../2015/Day20/Year2015Day20.h"
#include "../2015/Day21/Year2015Day21.h"
#include "../2015/Day22/Year2015Day22.h"
#include "../2015/Day23/Year2015Day23.h"
#include "../2015/Day24/Year2015Day24.h"
#include "../2015/Day25/Year2015Day25.h"

#include "../2016/Day1/Year2016Day1.h"
#include "../2016/Day2/Year2016Day2.h"
#include "../2016/Day3/Year2016Day3.h"
#include "../2016/Day4/Year2016Day4.h"
#include "../2016/Day5/Year2016Day5.h"
#include "../2016/Day6/Year2016Day6.h"
#include "../2016/Day7/Year2016Day7.h"
#include "../2016/Day8/Year2016Day8.h"
#include "../2016/Day9/Year2016Day9.h"
#include "../2016/Day10/Year2016Day10.h"
#include "../2016/Day11/Year2016Day11.h"
#include "../2016/Day12/Year2016Day12.h"
#include "../2016/Day13/Year2016Day13.h"
#include "../2016/Day14/Year2016Day14.h"
#include "../2016/Day15/Year2016Day15.h"
#include "../2016/Day16/Year2016Day16.h"
#include "../2016/Day17/Year2016Day17.h"
#include "../2016/Day18/Year2016Day18.h"
#include "../2016/Day19/Year2016Day19.h"
#include "../2016/Day20/Year2016Day20.h"
#include "../2016/Day21/Year2016Day21.h"
#include "../2016/Day22/Year2016Day22.h"
#include "../2016/Day23/Year2016Day23.h"
#include "../2016/Day24/Year2016Day24.h"
#include "../2016/Day25/Year2016Day25.h"

#include "../2017/Day1/Year2017Day1.h"
#include "../2017/Day2/Year2017Day2.h"
#include "../2017/Day3/Year2017Day3.h"
#include "../2017/Day4/Year2017Day4.h"
#include "../2017/Day5/Year2017Day5.h"
#include "../2017/Day6/Year2017Day6.h"
#include "../2017/Day7/Year2017Day7.h"
#include "../2017/Day8/Year2017Day8.h"
#include "../2017/Day9/Year2017Day9.h"
#include "../2017/Day10/Year2017Day10.h"
#include "../2017/Day11/Year2017Day11.h"
#include "../2017/Day12/Year2017Day12.h"
#include "../2017/Day13/Year2017Day13.h"
#include "../2017/Day14/Year2017Day14.h"
#include "../2017/Day15/Year2017Day15.h"
#include "../2017/Day16/Year2017Day16.h"
#include "../2017/Day17/Year2017Day17.h"
#include "../2017/Day18/Year2017Day18.h"
#include "../2017/Day19/Year2017Day19.h"
#include "../2017/Day20/Year2017Day20.h"
#include "../2017/Day21/Year2017Day21.h"
#include "../2017/Day22/Year2017Day22.h"
#include "../2017/Day23/Year2017Day23.h"
#include "../2017/Day24/Year2017Day24.h"
#include "../2017/Day25/Year2017Day25.h"

#include "../2018/Day1/Year2018Day1.h"
#include "../2018/Day2/Year2018Day2.h"
#include "../2018/Day3/Year2018Day3.h"
#include "../2018/Day4/Year2018Day4.h"
#include "../2018/Day5/Year2018Day5.h"
#include "../2018/Day6/Year2018Day6.h"
#include "../2018/Day7/Year2018Day7.h"
#include "../2018/Day8/Year2018Day8.h"
#include "../2018/Day9/Year2018Day9.h"
#include "../2018/Day10/Year2018Day10.h"
#include "../2018/Day11/Year2018Day11.h"
#include "../2018/Day12/Year2018Day12.h"
#include "../2018/Day13/Year2018Day13.h"
#include "../2018/Day14/Year2018Day14.h"
#include "../2018/Day15/Year2018Day15.h"
#include "../2018/Day16/Year2018Day16.h"
#include "../2018/Day17/Year2018Day17.h"
#include "../2018/Day18/Year2018Day18.h"
#include "../2018/Day19/Year2018Day19.h"
#include "../2018/Day20/Year2018Day20.h"
#include "../2018/Day21/Year2018Day21.h"
#include "../2018/Day22/Year2018Day22.h"
#include "../2018/Day23/Year2018Day23.h"
#include "../2018/Day24/Year2018Day24.h"
#include "../2018/Day25/Year2018Day25.h"

#include "../2019/Day1/Year2019Day1.h"
#include "../2019/Day2/Year2019Day2.h"
#include "../2019/Day3/Year2019Day3.h"
#include "../2019/Day4/Year2019Day4.h"
#include "../2019/Day5/Year2019Day5.h"
#include "../2019/Day6/Year2019Day6.h"
#include "../2019/Day7/Year2019Day7.h"
#include "../2019/Day8/Year2019Day8.h"
#include "../2019/Day9/Year2019Day9.h"
#include "../2019/Day10/Year2019Day10.h"
#include "../2019/Day11/Year2019Day11.h"
#include "../2019/Day12/Year2019Day12.h"
#include "../2019/Day13/Year2019Day13.h"
#include "../2019/Day14/Year2019Day14.h"
#include "../2019/Day15/Year2019Day15.h"
#include "../2019/Day16/Year2019Day16.h"
#include "../2019/Day17/Year2019Day17.h"
#include "../2019/Day18/Year2019Day18.h"
#include "../2019/Day19/Year2019Day19.h"
#include "../2019/Day20/Year2019Day20.h"
#include "../2019/Day21/Year2019Day21.h"
#include "../2019/Day22/Year2019Day22.h"
#include "../2019/Day23/Year2019Day23.h"
#include "../2019/Day24/Year2019Day24.h"
#include "../2019/Day25/Year2019Day25.h"

#include "../2020/Day1/Year2020Day1.h"
#include "../2020/Day2/Year2020Day2.h"
#include "../2020/Day3/Year2020Day3.h"
#include "../2020/Day4/Year2020Day4.h"
#include "../2020/Day5/Year2020Day5.h"
#include "../2020/Day6/Year2020Day6.h"
#include "../2020/Day7/Year2020Day7.h"
#include "../2020/Day8/Year2020Day8.h"
#include "../2020/Day9/Year2020Day9.h"
#include "../2020/Day10/Year2020Day10.h"
#include "../2020/Day11/Year2020Day11.h"
#include "../2020/Day12/Year2020Day12.h"
#include "../2020/Day13/Year2020Day13.h"
#include "../2020/Day14/Year2020Day14.h"
#include "../2020/Day15/Year2020Day15.h"
#include "../2020/Day16/Year2020Day16.h"
#include "../2020/Day17/Year2020Day17.h"
#include "../2020/Day18/Year2020Day18.h"
#include "../2020/Day19/Year2020Day19.h"
#include "../2020/Day20/Year2020Day20.h"
#include "../2020/Day21/Year2020Day21.h"
#include "../2020/Day22/Year2020Day22.h"
#include "../2020/Day23/Year2020Day23.h"
#include "../2020/Day24/Year2020Day24.h"
#include "../2020/Day25/Year2020Day25.h"

#include "../2021/Day1/Year2021Day1.h"
#include "../2021/Day2/Year2021Day2.h"
#include "../2021/Day3/Year2021Day3.h"
#include "../2021/Day4/Year2021Day4.h"
#include "../2021/Day5/Year2021Day5.h"
#include "../2021/Day6/Year2021Day6.h"
#include "../2021/Day7/Year2021Day7.h"
#include "../2021/Day8/Year2021Day8.h"
#include "../2021/Day9/Year2021Day9.h"
#include "../2021/Day10/Year2021Day10.h"
#include "../2021/Day11/Year2021Day11.h"
#include "../2021/Day12/Year2021Day12.h"
#include "../2021/Day13/Year2021Day13.h"
#include "../2021/Day14/Year2021Day14.h"
#include "../2021/Day15/Year2021Day15.h"
#include "../2021/Day16/Year2021Day16.h"
#include "../2021/Day17/Year2021Day17.h"
#include "../2021/Day18/Year2021Day18.h"
#include "../2021/Day19/Year2021Day19.h"
#include "../2021/Day20/Year2021Day20.h"
#include "../2021/Day21/Year2021Day21.h"
#include "../2021/Day22/Year2021Day22.h"
#include "../2021/Day23/Year2021Day23.h"
#include "../2021/Day24/Year2021Day24.h"
#include "../2021/Day25/Year2021Day25.h"

#include "../2022/Day1/Year2022Day1.h"
#include "../2022/Day2/Year2022Day2.h"
#include "../2022/Day3/Year2022Day3.h"
#include "../2022/Day4/Year2022Day4.h"
#include "../2022/Day5/Year2022Day5.h"
#include "../2022/Day6/Year2022Day6.h"
#include "../2022/Day7/Year2022Day7.h"
#include "../2022/Day8/Year2022Day8.h"
#include "../2022/Day9/Year2022Day9.h"
#include "../2022/Day10/Year2022Day10.h"
#include "../2022/Day11/Year2022Day11.h"
#include "../2022/Day12/Year2022Day12.h"
#include "../2022/Day13/Year2022Day13.h"
#include "../2022/Day14/Year2022Day14.h"
#include "../2022/Day15/Year2022Day15.h"
#include "../2022/Day16/Year2022Day16.h"
#include "../2022/Day17/Year2022Day17.h"
#include "../2022/Day18/Year2022Day18.h"
#include "../2022/Day19/Year2022Day19.h"
#include "../2022/Day20/Year2022Day20.h"
#include "../2022/Day21/Year2022Day21.h"
#include "../2022/Day22/Year2022Day22.h"
#include "../2022/Day23/Year2022Day23.h"
#include "../2022/Day24/Year2022Day24.h"
#include "../2022/Day25/Year2022Day25.h"

#include "../2023/Day1/Year2023Day1.h"
#include "../2023/Day2/Year2023Day2.h"
#include "../2023/Day3/Year2023Day3.h"
#include "../2023/Day4/Year2023Day4.h"
#include "../2023/Day5/Year2023Day5.h"
#include "../2023/Day6/Year2023Day6.h"
#include "../2023/Day7/Year2023Day7.h"
#include "../2023/Day8/Year2023Day8.h"
#include "../2023/Day9/Year2023Day9.h"
#include "../2023/Day10/Year2023Day10.h"
#include "../2023/Day11/Year2023Day11.h"
#include "../2023/Day12/Year2023Day12.h"
#include "../2023/Day13/Year2023Day13.h"
#include "../2023/Day14/Year2023Day14.h"
#include "../2023/Day15/Year2023Day15.h"
#include "../2023/Day16/Year2023Day16.h"
#include "../2023/Day17/Year2023Day17.h"
#include "../2023/Day18/Year2023Day18.h"
#include "../2023/Day19/Year2023Day19.h"
#include "../2023/Day20/Year2023Day20.h"
#include "../2023/Day21/Year2023Day21.h"
#include "../2023/Day22/Year2023Day22.h"
#include "../2023/Day23/Year2023Day23.h"
#include "../2023/Day24/Year2023Day24.h"
#include "../2023/Day25/Year2023Day25.h"

#include "../2024/Day1/Year2024Day1.h"
#include "../2024/Day2/Year2024Day2.h"
#include "../2024/Day3/Year2024Day3.h"
#include "../2024/Day4/Year2024Day4.h"
#include "../2024/Day5/Year2024Day5.h"
#include "../2024/Day6/Year2024Day6.h"
#include "../2024/Day7/Year2024Day7.h"
#include "../2024/Day8/Year2024Day8.h"
#include "../2024/Day9/Year2024Day9.h"
#include "../2024/Day10/Year2024Day10.h"
#include "../2024/Day11/Year2024Day11.h"
#include "../2024/Day12/Year2024Day12.h"
#include "../2024/Day13/Year2024Day13.h"
#include "../2024/Day14/Year2024Day14.h"
#include "../2024/Day15/Year2024Day15.h"
#include "../2024/Day16/Year2024Day16.h"
#include "../2024/Day17/Year2024Day17.h"
#include "../2024/Day18/Year2024Day18.h"
#include "../2024/Day19/Year2024Day19.h"
#include "../2024/Day20/Year2024Day20.h"
#include "../2024/Day21/Year2024Day21.h"
#include "../2024/Day22/Year2024Day22.h"
#include "../2024/Day23/Year2024Day23.h"
#include "../2024/Day24/Year2024Day24.h"
#include "../2024/Day25/Year2024Day25.h"

#include "../2025/Day1/Year2025Day1.h"
#include "../2025/Day2/Year2025Day2.h"
#include "../2025/Day3/Year2025Day3.h"
#include "../2025/Day4/Year2025Day4.h"
#include "../2025/Day5/Year2025Day5.h"
#include "../2025/Day6/Year2025Day6.h"
#include "../2025/Day7/Year2025Day7.h"
#include "../2025/Day8/Year2025Day8.h"
#include "../2025/Day9/Year2025Day9.h"
#include "../2025/Day10/Year2025Day10.h"
#include "../2025/Day11/Year2025Day11.h"
#include "../2025/Day12/Year2025Day12.h"

void RunTranslate::RunCorrectFunction(int year, int day, int inputType) {
    switch (year) {
        case 2015:
            RunCorrectday2015(day, CreatePath(year, day, inputType));
            break;
        case 2016:
            RunCorrectday2016(day, CreatePath(year, day, inputType));
            break;
        case 2017:
            RunCorrectday2017(day, CreatePath(year, day, inputType));
            break;
        case 2018:
            RunCorrectday2018(day, CreatePath(year, day, inputType));
            break;
        case 2019:
            RunCorrectday2019(day, CreatePath(year, day, inputType));
            break;
        case 2020:
            RunCorrectday2020(day, CreatePath(year, day, inputType));
            break;
        case 2021:
            RunCorrectday2021(day, CreatePath(year, day, inputType));
            break;
        case 2022:
            RunCorrectday2022(day, CreatePath(year, day, inputType));
            break;
        case 2023:
            RunCorrectday2023(day, CreatePath(year, day, inputType));
            break;
        case 2024:
            RunCorrectday2024(day, CreatePath(year, day, inputType));
            break;
        case 2025:
            RunCorrectday2025(day, CreatePath(year, day, inputType));
            break;
        default:
            return;
    }
}

void RunTranslate::RunCorrectday2015(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2015Day1::Run(filenamePath);
            break;
        case 2:
            Year2015Day2::Run(filenamePath);
            break;
        case 3:
            Year2015Day3::Run(filenamePath);
            break;
        case 4:
            Year2015Day4::Run(filenamePath);
            break;
        case 5:
            Year2015Day5::Run(filenamePath);
            break;
        case 6:
            Year2015Day6::Run(filenamePath);
            break;
        case 7:
            Year2015Day7::Run(filenamePath);
            break;
        case 8:
            Year2015Day8::Run(filenamePath);
            break;
        case 9:
            Year2015Day9::Run(filenamePath);
            break;
        case 10:
            Year2015Day10::Run(filenamePath);
            break;
        case 11:
            Year2015Day11::Run(filenamePath);
            break;
        case 12:
            Year2015Day12::Run(filenamePath);
            break;
        case 13:
            Year2015Day13::Run(filenamePath);
            break;
        case 14:
            Year2015Day14::Run(filenamePath);
            break;
        case 15:
            Year2015Day15::Run(filenamePath);
            break;
        case 16:
            Year2015Day16::Run(filenamePath);
            break;
        case 17:
            Year2015Day17::Run(filenamePath);
            break;
        case 18:
            Year2015Day18::Run(filenamePath);
            break;
        case 19:
            Year2015Day19::Run(filenamePath);
            break;
        case 20:
            Year2015Day20::Run(filenamePath);
            break;
        case 21:
            Year2015Day21::Run(filenamePath);
            break;
        case 22:
            Year2015Day22::Run(filenamePath);
            break;
        case 23:
            Year2015Day23::Run(filenamePath);
            break;
        case 24:
            Year2015Day24::Run(filenamePath);
            break;
        case 25:
            Year2015Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2016(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2016Day1::Run(filenamePath);
            break;
        case 2:
            Year2016Day2::Run(filenamePath);
            break;
        case 3:
            Year2016Day3::Run(filenamePath);
            break;
        case 4:
            Year2016Day4::Run(filenamePath);
            break;
        case 5:
            Year2016Day5::Run(filenamePath);
            break;
        case 6:
            Year2016Day6::Run(filenamePath);
            break;
        case 7:
            Year2016Day7::Run(filenamePath);
            break;
        case 8:
            Year2016Day8::Run(filenamePath);
            break;
        case 9:
            Year2016Day9::Run(filenamePath);
            break;
        case 10:
            Year2016Day10::Run(filenamePath);
            break;
        case 11:
            Year2016Day11::Run(filenamePath);
            break;
        case 12:
            Year2016Day12::Run(filenamePath);
            break;
        case 13:
            Year2016Day13::Run(filenamePath);
            break;
        case 14:
            Year2016Day14::Run(filenamePath);
            break;
        case 15:
            Year2016Day15::Run(filenamePath);
            break;
        case 16:
            Year2016Day16::Run(filenamePath);
            break;
        case 17:
            Year2016Day17::Run(filenamePath);
            break;
        case 18:
            Year2016Day18::Run(filenamePath);
            break;
        case 19:
            Year2016Day19::Run(filenamePath);
            break;
        case 20:
            Year2016Day20::Run(filenamePath);
            break;
        case 21:
            Year2016Day21::Run(filenamePath);
            break;
        case 22:
            Year2016Day22::Run(filenamePath);
            break;
        case 23:
            Year2016Day23::Run(filenamePath);
            break;
        case 24:
            Year2016Day24::Run(filenamePath);
            break;
        case 25:
            Year2016Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2017(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2017Day1::Run(filenamePath);
            break;
        case 2:
            Year2017Day2::Run(filenamePath);
            break;
        case 3:
            Year2017Day3::Run(filenamePath);
            break;
        case 4:
            Year2017Day4::Run(filenamePath);
            break;
        case 5:
            Year2017Day5::Run(filenamePath);
            break;
        case 6:
            Year2017Day6::Run(filenamePath);
            break;
        case 7:
            Year2017Day7::Run(filenamePath);
            break;
        case 8:
            Year2017Day8::Run(filenamePath);
            break;
        case 9:
            Year2017Day9::Run(filenamePath);
            break;
        case 10:
            Year2017Day10::Run(filenamePath);
            break;
        case 11:
            Year2017Day11::Run(filenamePath);
            break;
        case 12:
            Year2017Day12::Run(filenamePath);
            break;
        case 13:
            Year2017Day13::Run(filenamePath);
            break;
        case 14:
            Year2017Day14::Run(filenamePath);
            break;
        case 15:
            Year2017Day15::Run(filenamePath);
            break;
        case 16:
            Year2017Day16::Run(filenamePath);
            break;
        case 17:
            Year2017Day17::Run(filenamePath);
            break;
        case 18:
            Year2017Day18::Run(filenamePath);
            break;
        case 19:
            Year2017Day19::Run(filenamePath);
            break;
        case 20:
            Year2017Day20::Run(filenamePath);
            break;
        case 21:
            Year2017Day21::Run(filenamePath);
            break;
        case 22:
            Year2017Day22::Run(filenamePath);
            break;
        case 23:
            Year2017Day23::Run(filenamePath);
            break;
        case 24:
            Year2017Day24::Run(filenamePath);
            break;
        case 25:
            Year2017Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2018(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2018Day1::Run(filenamePath);
            break;
        case 2:
            Year2018Day2::Run(filenamePath);
            break;
        case 3:
            Year2018Day3::Run(filenamePath);
            break;
        case 4:
            Year2018Day4::Run(filenamePath);
            break;
        case 5:
            Year2018Day5::Run(filenamePath);
            break;
        case 6:
            Year2018Day6::Run(filenamePath);
            break;
        case 7:
            Year2018Day7::Run(filenamePath);
            break;
        case 8:
            Year2018Day8::Run(filenamePath);
            break;
        case 9:
            Year2018Day9::Run(filenamePath);
            break;
        case 10:
            Year2018Day10::Run(filenamePath);
            break;
        case 11:
            Year2018Day11::Run(filenamePath);
            break;
        case 12:
            Year2018Day12::Run(filenamePath);
            break;
        case 13:
            Year2018Day13::Run(filenamePath);
            break;
        case 14:
            Year2018Day14::Run(filenamePath);
            break;
        case 15:
            Year2018Day15::Run(filenamePath);
            break;
        case 16:
            Year2018Day16::Run(filenamePath);
            break;
        case 17:
            Year2018Day17::Run(filenamePath);
            break;
        case 18:
            Year2018Day18::Run(filenamePath);
            break;
        case 19:
            Year2018Day19::Run(filenamePath);
            break;
        case 20:
            Year2018Day20::Run(filenamePath);
            break;
        case 21:
            Year2018Day21::Run(filenamePath);
            break;
        case 22:
            Year2018Day22::Run(filenamePath);
            break;
        case 23:
            Year2018Day23::Run(filenamePath);
            break;
        case 24:
            Year2018Day24::Run(filenamePath);
            break;
        case 25:
            Year2018Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2019(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2019Day1::Run(filenamePath);
            break;
        case 2:
            Year2019Day2::Run(filenamePath);
            break;
        case 3:
            Year2019Day3::Run(filenamePath);
            break;
        case 4:
            Year2019Day4::Run(filenamePath);
            break;
        case 5:
            Year2019Day5::Run(filenamePath);
            break;
        case 6:
            Year2019Day6::Run(filenamePath);
            break;
        case 7:
            Year2019Day7::Run(filenamePath);
            break;
        case 8:
            Year2019Day8::Run(filenamePath);
            break;
        case 9:
            Year2019Day9::Run(filenamePath);
            break;
        case 10:
            Year2019Day10::Run(filenamePath);
            break;
        case 11:
            Year2019Day11::Run(filenamePath);
            break;
        case 12:
            Year2019Day12::Run(filenamePath);
            break;
        case 13:
            Year2019Day13::Run(filenamePath);
            break;
        case 14:
            Year2019Day14::Run(filenamePath);
            break;
        case 15:
            Year2019Day15::Run(filenamePath);
            break;
        case 16:
            Year2019Day16::Run(filenamePath);
            break;
        case 17:
            Year2019Day17::Run(filenamePath);
            break;
        case 18:
            Year2019Day18::Run(filenamePath);
            break;
        case 19:
            Year2019Day19::Run(filenamePath);
            break;
        case 20:
            Year2019Day20::Run(filenamePath);
            break;
        case 21:
            Year2019Day21::Run(filenamePath);
            break;
        case 22:
            Year2019Day22::Run(filenamePath);
            break;
        case 23:
            Year2019Day23::Run(filenamePath);
            break;
        case 24:
            Year2019Day24::Run(filenamePath);
            break;
        case 25:
            Year2019Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2020(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2020Day1::Run(filenamePath);
            break;
        case 2:
            Year2020Day2::Run(filenamePath);
            break;
        case 3:
            Year2020Day3::Run(filenamePath);
            break;
        case 4:
            Year2020Day4::Run(filenamePath);
            break;
        case 5:
            Year2020Day5::Run(filenamePath);
            break;
        case 6:
            Year2020Day6::Run(filenamePath);
            break;
        case 7:
            Year2020Day7::Run(filenamePath);
            break;
        case 8:
            Year2020Day8::Run(filenamePath);
            break;
        case 9:
            Year2020Day9::Run(filenamePath);
            break;
        case 10:
            Year2020Day10::Run(filenamePath);
            break;
        case 11:
            Year2020Day11::Run(filenamePath);
            break;
        case 12:
            Year2020Day12::Run(filenamePath);
            break;
        case 13:
            Year2020Day13::Run(filenamePath);
            break;
        case 14:
            Year2020Day14::Run(filenamePath);
            break;
        case 15:
            Year2020Day15::Run(filenamePath);
            break;
        case 16:
            Year2020Day16::Run(filenamePath);
            break;
        case 17:
            Year2020Day17::Run(filenamePath);
            break;
        case 18:
            Year2020Day18::Run(filenamePath);
            break;
        case 19:
            Year2020Day19::Run(filenamePath);
            break;
        case 20:
            Year2020Day20::Run(filenamePath);
            break;
        case 21:
            Year2020Day21::Run(filenamePath);
            break;
        case 22:
            Year2020Day22::Run(filenamePath);
            break;
        case 23:
            Year2020Day23::Run(filenamePath);
            break;
        case 24:
            Year2020Day24::Run(filenamePath);
            break;
        case 25:
            Year2020Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2021(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2021Day1::Run(filenamePath);
            break;
        case 2:
            Year2021Day2::Run(filenamePath);
            break;
        case 3:
            Year2021Day3::Run(filenamePath);
            break;
        case 4:
            Year2021Day4::Run(filenamePath);
            break;
        case 5:
            Year2021Day5::Run(filenamePath);
            break;
        case 6:
            Year2021Day6::Run(filenamePath);
            break;
        case 7:
            Year2021Day7::Run(filenamePath);
            break;
        case 8:
            Year2021Day8::Run(filenamePath);
            break;
        case 9:
            Year2021Day9::Run(filenamePath);
            break;
        case 10:
            Year2021Day10::Run(filenamePath);
            break;
        case 11:
            Year2021Day11::Run(filenamePath);
            break;
        case 12:
            Year2021Day12::Run(filenamePath);
            break;
        case 13:
            Year2021Day13::Run(filenamePath);
            break;
        case 14:
            Year2021Day14::Run(filenamePath);
            break;
        case 15:
            Year2021Day15::Run(filenamePath);
            break;
        case 16:
            Year2021Day16::Run(filenamePath);
            break;
        case 17:
            Year2021Day17::Run(filenamePath);
            break;
        case 18:
            Year2021Day18::Run(filenamePath);
            break;
        case 19:
            Year2021Day19::Run(filenamePath);
            break;
        case 20:
            Year2021Day20::Run(filenamePath);
            break;
        case 21:
            Year2021Day21::Run(filenamePath);
            break;
        case 22:
            Year2021Day22::Run(filenamePath);
            break;
        case 23:
            Year2021Day23::Run(filenamePath);
            break;
        case 24:
            Year2021Day24::Run(filenamePath);
            break;
        case 25:
            Year2021Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2022(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2022Day1::Run(filenamePath);
            break;
        case 2:
            Year2022Day2::Run(filenamePath);
            break;
        case 3:
            Year2022Day3::Run(filenamePath);
            break;
        case 4:
            Year2022Day4::Run(filenamePath);
            break;
        case 5:
            Year2022Day5::Run(filenamePath);
            break;
        case 6:
            Year2022Day6::Run(filenamePath);
            break;
        case 7:
            Year2022Day7::Run(filenamePath);
            break;
        case 8:
            Year2022Day8::Run(filenamePath);
            break;
        case 9:
            Year2022Day9::Run(filenamePath);
            break;
        case 10:
            Year2022Day10::Run(filenamePath);
            break;
        case 11:
            Year2022Day11::Run(filenamePath);
            break;
        case 12:
            Year2022Day12::Run(filenamePath);
            break;
        case 13:
            Year2022Day13::Run(filenamePath);
            break;
        case 14:
            Year2022Day14::Run(filenamePath);
            break;
        case 15:
            Year2022Day15::Run(filenamePath);
            break;
        case 16:
            Year2022Day16::Run(filenamePath);
            break;
        case 17:
            Year2022Day17::Run(filenamePath);
            break;
        case 18:
            Year2022Day18::Run(filenamePath);
            break;
        case 19:
            Year2022Day19::Run(filenamePath);
            break;
        case 20:
            Year2022Day20::Run(filenamePath);
            break;
        case 21:
            Year2022Day21::Run(filenamePath);
            break;
        case 22:
            Year2022Day22::Run(filenamePath);
            break;
        case 23:
            Year2022Day23::Run(filenamePath);
            break;
        case 24:
            Year2022Day24::Run(filenamePath);
            break;
        case 25:
            Year2022Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2023(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2023Day1::Run(filenamePath);
            break;
        case 2:
            Year2023Day2::Run(filenamePath);
            break;
        case 3:
            Year2023Day3::Run(filenamePath);
            break;
        case 4:
            Year2023Day4::Run(filenamePath);
            break;
        case 5:
            Year2023Day5::Run(filenamePath);
            break;
        case 6:
            Year2023Day6::Run(filenamePath);
            break;
        case 7:
            Year2023Day7::Run(filenamePath);
            break;
        case 8:
            Year2023Day8::Run(filenamePath);
            break;
        case 9:
            Year2023Day9::Run(filenamePath);
            break;
        case 10:
            Year2023Day10::Run(filenamePath);
            break;
        case 11:
            Year2023Day11::Run(filenamePath);
            break;
        case 12:
            Year2023Day12::Run(filenamePath);
            break;
        case 13:
            Year2023Day13::Run(filenamePath);
            break;
        case 14:
            Year2023Day14::Run(filenamePath);
            break;
        case 15:
            Year2023Day15::Run(filenamePath);
            break;
        case 16:
            Year2023Day16::Run(filenamePath);
            break;
        case 17:
            Year2023Day17::Run(filenamePath);
            break;
        case 18:
            Year2023Day18::Run(filenamePath);
            break;
        case 19:
            Year2023Day19::Run(filenamePath);
            break;
        case 20:
            Year2023Day20::Run(filenamePath);
            break;
        case 21:
            Year2023Day21::Run(filenamePath);
            break;
        case 22:
            Year2023Day22::Run(filenamePath);
            break;
        case 23:
            Year2023Day23::Run(filenamePath);
            break;
        case 24:
            Year2023Day24::Run(filenamePath);
            break;
        case 25:
            Year2023Day25::Run(filenamePath);
            break;
        default:
            break;
    }
}

void RunTranslate::RunCorrectday2024(int day, std::string filenamePath) {
    switch (day) {
        case 1:
            Year2024Day1::Run(filenamePath);
            break;
        case 2:
            Year2024Day2::Run(filenamePath);
            break;
        case 3:
            Year2024Day3::Run(filenamePath);
            break;
        case 4:
            Year2024Day4::Run(filenamePath);
            break;
        case 5:
            Year2024Day5::Run(filenamePath);
            break;
        case 6:
            Year2024Day6::Run(filenamePath);
            break;
        case 7:
            Year2024Day7::Run(filenamePath);
            break;
        case 8:
            Year2024Day8::Run(filenamePath);
            break;
        case 9:
            Year2024Day9::Run(filenamePath);
            break;
        case 10:
            Year2024Day10::Run(filenamePath);
            break;
        case 11:
            Year2024Day11::Run(filenamePath);
            break;
        case 12:
            Year2024Day12::Run(filenamePath);
            break;
        case 13:
            Year2024Day13::Run(filenamePath);
            break;
        case 14:
            Year2024Day14::Run(filenamePath);
            break;
        case 15:
            Year2024Day15::Run(filenamePath);
            break;
        case 16:
            Year2024Day16::Run(filenamePath);
            break;
        case 17:
            Year2024Day17::Run(filenamePath);
            break;
        case 18:
            Year2024Day18::Run(filenamePath);
            break;
        case 19:
            Year2024Day19::Run(filenamePath);
            break;
        case 20:
            Year2024Day20::Run(filenamePath);
            break;
        case 21:
            Year2024Day21::Run(filenamePath);
            break;
        case 22:
            Year2024Day22::Run(filenamePath);
            break;
        case 23:
            Year2024Day23::Run(filenamePath);
            break;
        case 24:
            Year2024Day24::Run(filenamePath);
            break;
        case 25:
            Year2024Day25::Run(filenamePath);
            break;
        default:
            break;
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
        case 5:
            Year2025Day5::Run(filenamePath);
            break;
        case 6:
            Year2025Day6::Run(filenamePath);
            break;
        case 7:
            Year2025Day7::Run(filenamePath);
            break;
        case 8:
            Year2025Day8::Run(filenamePath);
            break;
        case 9:
            Year2025Day9::Run(filenamePath);
            break;
        case 10:
            Year2025Day10::Run(filenamePath);
            break;
        case 11:
            Year2025Day11::Run(filenamePath);
            break;
        case 12:
            Year2025Day12::Run(filenamePath);
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
