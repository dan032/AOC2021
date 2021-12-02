cmake_minimum_required(VERSION 3.6)
project(AOC2021)

set(CMAKE_CXX_STANDARD 14)


add_executable(AOC2021
        aoc2021.cpp
        day01/day01.cpp day02/day02.cpp day03/day03.cpp
        )
target_link_libraries(AOC2021 m)