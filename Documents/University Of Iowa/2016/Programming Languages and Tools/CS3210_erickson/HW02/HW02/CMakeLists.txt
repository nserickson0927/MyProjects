cmake_minimum_required(VERSION 2.6)
project(hw02)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw02 main.cpp)

install(TARGETS hw02 RUNTIME DESTINATION bin)
