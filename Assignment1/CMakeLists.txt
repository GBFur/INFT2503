cmake_minimum_required(VERSION 3.5)

project(assignment01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra")

add_executable(assignment01 temperatur.cpp)
add_executable(assignment01b temperaturB.cpp)