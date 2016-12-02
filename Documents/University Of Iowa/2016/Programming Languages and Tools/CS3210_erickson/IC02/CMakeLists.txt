cmake_minimum_required(VERSION 2.6)
project(ic02)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ic02 main.cpp)

install(TARGETS ic02 RUNTIME DESTINATION bin)
