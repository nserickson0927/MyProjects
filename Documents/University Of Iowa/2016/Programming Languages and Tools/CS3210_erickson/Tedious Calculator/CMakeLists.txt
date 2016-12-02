cmake_minimum_required(VERSION 3.6)
project(Tedious_Calculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Calculator.h Calculator.cpp)
add_executable(Tedious_Calculator ${SOURCE_FILES})