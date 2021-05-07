cmake_minimum_required(VERSION 3.0.0)
project(studlist VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(${PROJECT_SOURCE_DIR})
add_executable(app ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/funkcijos.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
