cmake_minimum_required(VERSION 2.6)
project(ic04)

add_executable(ic04 main.cpp)

install(TARGETS ic04 RUNTIME DESTINATION bin)
