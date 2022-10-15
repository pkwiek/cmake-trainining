cmake_minimum_required(VERSION 3.22)
project(StructuredProjectExample LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

enable_testing()

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(src)
