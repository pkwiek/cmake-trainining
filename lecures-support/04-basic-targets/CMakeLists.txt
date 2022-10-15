cmake_minimum_required(VERSION 3.22)
project(BasicTargets)

add_library(MyLibrary STATIC ExampleClass.cpp)

add_executable(MyApplication main.cpp)

target_link_libraries(MyApplication MyLibrary)
