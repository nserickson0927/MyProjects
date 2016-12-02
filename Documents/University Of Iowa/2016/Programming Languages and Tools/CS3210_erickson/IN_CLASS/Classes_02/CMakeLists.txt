cmake_minimum_required(VERSION 2.6)
project(classes_01)

set(CMAKE_CXX_STANDARD 14)                                                                                                                                               
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(classes_01 main.cpp vector.cpp) 
#add_executable(viruses Patient.cc Patient.h Virus.cc Virus.h simulation.cc)
#add_executable(MIT MITPerson.cc Student.cc)

install(TARGETS classes_01 RUNTIME DESTINATION bin)
