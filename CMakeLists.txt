cmake_minimum_required(VERSION 2.8.4)
project(cs162)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(LAB_1_2_FILES
    labs/lab1/f.h
    labs/lab1/g.h
    labs/lab1/f.cpp
    labs/lab1/g.cpp
    labs/lab1/lab1-2.cpp
)

add_executable(lab1-1 labs/lab1/lab1-1.cpp)
add_executable(lab1-2 ${LAB_1_2_FILES})