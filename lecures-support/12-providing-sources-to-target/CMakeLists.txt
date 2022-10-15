cmake_minimum_required(VERSION 3.22)
project(ProvidingSourcesToTarget)

set(CMAKE_CXX_STANDARD 14)

#set(SRC_FILES FileLoader.cpp
#              FileWriter.cpp)

aux_source_directory(. SRC_FILES)

#file(GLOB SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(Library STATIC ${SRC_FILES})