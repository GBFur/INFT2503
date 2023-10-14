cmake_minimum_required(VERSION 3.5)

project(assignment06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(oppgave1 oppgave1.cpp)
add_executable(oppgave2 oppgave2.cpp)