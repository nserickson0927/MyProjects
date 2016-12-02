cmake_minimum_required(VERSION 2.6)
project(sjbdl)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sjbdl main.cpp)

install(TARGETS sjbdl RUNTIME DESTINATION bin)
