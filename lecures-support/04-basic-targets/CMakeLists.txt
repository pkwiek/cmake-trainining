cmake_minimum_required(VERSION 3.16)
project(BasicTargets)

add_library(MyApplication STATIC ExampleClass.cpp)
add_executable(MyApplication main.cpp)
