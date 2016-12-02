cmake_minimum_required(VERSION 2.6)
project(ic01)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ic01 main.cpp)

install(TARGETS ic01 RUNTIME DESTINATION bin)
