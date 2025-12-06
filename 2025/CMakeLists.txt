# Get year from folder name
get_filename_component(YEAR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

foreach(DAY RANGE 1 12)
    set(DAY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Day${DAY}")

    # Skip non-existing day folders
    if (EXISTS "${DAY_DIR}")
        set(CPP_FILE "${DAY_DIR}/Year${YEAR_NAME}Day${DAY}.cpp")
        set(H_FILE   "${DAY_DIR}/Year${YEAR_NAME}Day${DAY}.h"
                Day5/Range.cpp
                Day5/Range.h)

        # Only add the library if the cpp file exists
        if (EXISTS "${CPP_FILE}")
            set(TARGET_NAME "Year${YEAR_NAME}Day${DAY}")

            add_library(${TARGET_NAME}
                    ${CPP_FILE}
                    ${H_FILE}
            )

            target_include_directories(${TARGET_NAME}
                    PUBLIC ${DAY_DIR}
            )
        endif()
    endif()
endforeach()