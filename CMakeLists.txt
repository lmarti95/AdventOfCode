cmake_minimum_required(VERSION 4.0)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdventOfCode main.cpp
        Shared/ReadHelper.cpp
        Shared/ReadHelper.h
        Shared/Menu.cpp
        Shared/Menu.h
        Shared/RunTranslate.cpp
        Shared/RunTranslate.h
        2025/Day1/Year2025Day1.cpp
        2025/Day1/Year2025Day1.h)
