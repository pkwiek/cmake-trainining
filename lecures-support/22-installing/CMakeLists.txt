cmake_minimum_required(VERSION 3.22)
project(StructuredProjectExample LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(src)

add_custom_target(CreateInstaller
        COMMAND ${CMAKE_COMMAND} --build . --target install
        COMMENT "Running install target"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})