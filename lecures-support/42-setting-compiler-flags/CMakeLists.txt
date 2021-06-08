cmake_minimum_required(VERSION 3.16)
project(StructuredProjectExample LANGUAGES CXX VERSION 1.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(cmake/AddSanitizerFlagsIfNeeded.cmake)

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(src)