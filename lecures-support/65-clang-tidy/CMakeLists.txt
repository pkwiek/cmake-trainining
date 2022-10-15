cmake_minimum_required(VERSION 3.22)
project(ClangTidyExample LANGUAGES CXX)

list(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)