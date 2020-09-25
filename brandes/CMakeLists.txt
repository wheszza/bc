cmake_minimum_required(VERSION 3.5)
project(brandes)
set(SOURCE_FILES src/brandes.cxx
    src/parse.h
    src/graph.h
    src/dependency_calculator.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})