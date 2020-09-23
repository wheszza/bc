cmake_minimum_required(VERSION 3.5)
project(brandes CXX)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

set(SOURCE_FILES src/brandes.cxx
    src/parse.h
    src/graph.h
    src/dependency_calculator.h)

add_executable(brandes ${SOURCE_FILES})
