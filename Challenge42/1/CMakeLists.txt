cmake_minimum_required(VERSION 3.17)
project(COMPLEXITY)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(benchmark)

add_executable(COMPLEXITY binary_search.cpp)
target_link_libraries(COMPLEXITY benchmark::benchmark)