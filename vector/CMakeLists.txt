cmake_minimum_required(VERSION 3.0.0)


set(This app)
project(${This} C CXX)
set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CTest)
enable_testing()

add_subdirectory(googletest)


add_library(app  main.cpp funkcijos.cpp funkcijos.h )
add_executable(app2.0  main.cpp funkcijos.cpp funkcijos.h )

add_subdirectory(test)


