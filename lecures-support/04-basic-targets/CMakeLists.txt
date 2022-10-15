cmake_minimum_required(VERSION 3.22)
project(BasicTargets)

add_library(MyApplication STATIC ExampleClass.cpp)
add_executable(MyApplication main.cpp)
