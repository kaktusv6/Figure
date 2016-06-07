cmake_minimum_required(VERSION 3.3)
project(Figure)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Figuires/Figure.h
        Figuires/Figure.cpp
        Figuires/Point.cpp
        Figuires/Segment.cpp
        Figuires/Cercle.cpp
        Figuires/Rectangle.cpp
        Figuires/Square.cpp)

add_executable(Figure ${SOURCE_FILES})