cmake_minimum_required(VERSION 3.17)
project(COMPLEXITY)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(benchmark)

add_executable(COMPLEXITY strassen.cpp)
target_link_libraries(COMPLEXITY benchmark::benchmark)