#aux_source_directory(. SRC_LIST)
set(SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE .)

add_subdirectory(skipList)


add_executable(run_tests ${SOURCE})
target_link_libraries(run_tests skipList)


