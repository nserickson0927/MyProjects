cmake_minimum_required(VERSION 2.6)
project(hw01)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(HW01_SRCS HW01.cpp main.cpp)

qt4_automoc(${HW01_SRCS})
add_executable(hw01 ${HW01_SRCS})
target_link_libraries(hw01 ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS hw01 RUNTIME DESTINATION bin)
