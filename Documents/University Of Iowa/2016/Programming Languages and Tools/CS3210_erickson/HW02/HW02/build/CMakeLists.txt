cmake_minimum_required(VERSION 3.6)
project(build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CMakeFiles/3.4.3/CompilerIdC/CMakeCCompilerId.c
    CMakeFiles/3.4.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
    CMakeFiles/feature_tests.c
    CMakeFiles/feature_tests.cxx)

add_executable(build ${SOURCE_FILES})