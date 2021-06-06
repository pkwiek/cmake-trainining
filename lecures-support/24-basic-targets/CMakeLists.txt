cmake_minimum_required(VERSION 3.16)
project(BasicTargets)

set(SRC_FILES main.cpp ExampleClass.cpp)

add_library(MyApplication STATIC ${SRC_FILES})
#add_library(MyApplication SHARED ${SRC_FILES})
#add_executable(MyApplication ${SRC_FILES})