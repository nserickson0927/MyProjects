cmake_minimum_required(VERSION 2.6)
project(blah)

add_executable(blah main.cpp)

install(TARGETS blah RUNTIME DESTINATION bin)
