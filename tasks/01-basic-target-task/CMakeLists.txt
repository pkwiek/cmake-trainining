cmake_minimum_required(VERSION 3.22)

project(vectors LANGUAGES CXX)

set(SOURCES
        main.cpp
        Vector3.cpp
        VectorPrinter.cpp)
add_executable(app ${SOURCES})