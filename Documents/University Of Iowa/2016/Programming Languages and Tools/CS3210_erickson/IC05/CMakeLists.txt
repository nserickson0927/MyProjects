cmake_minimum_required(VERSION 2.6)
project(ic05)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ic05 main.cpp vector.cpp)

install(TARGETS ic05 RUNTIME DESTINATION bin)
