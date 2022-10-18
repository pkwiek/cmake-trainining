set(LIB_NAME file-loader)

project(${LIB_NAME})

set(SOURCES FileWriter.cpp FileLoader.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
target_include_directories(${LIB_NAME} INTERFACE .)

