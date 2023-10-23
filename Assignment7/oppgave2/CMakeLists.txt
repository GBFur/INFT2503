cmake_minimum_required(VERSION 3.5)

project(assignment07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra")

add_executable(set set.hpp main.cpp)