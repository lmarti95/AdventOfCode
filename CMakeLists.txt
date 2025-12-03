cmake_minimum_required(VERSION 3.20)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Main executable ---
add_executable(AdventOfCode
        main.cpp
        Shared/ReadHelper.cpp
        Shared/Menu.cpp
        Shared/RunTranslate.cpp
        Shared/StringHelper.cpp
)

target_include_directories(AdventOfCode PRIVATE Shared)

# --- Add all year folders ---
foreach(YEAR RANGE 2015 2025)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${YEAR}")
        add_subdirectory(${YEAR})
    endif()
endforeach()

# --- Link all yearly/day libraries ---
foreach(YEAR RANGE 2015 2025)
    foreach(DAY RANGE 1 24)
        set(TARGET_NAME "Year${YEAR}Day${DAY}")
        if (TARGET ${TARGET_NAME})
            target_link_libraries(AdventOfCode PRIVATE ${TARGET_NAME})
        endif()
    endforeach()
endforeach()