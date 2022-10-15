cmake_minimum_required(VERSION 3.22)
project(ClangTidyExample LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(UseClangTidy)

add_subdirectory(src)