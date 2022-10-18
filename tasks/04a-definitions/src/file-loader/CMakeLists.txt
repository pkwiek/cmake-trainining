set(LIB_NAME file-loader)

project(${LIB_NAME})

option(MY_FILE_LOADER_AS_SHARED "OFF" "Build file-loader library as a shared library instead of a static")

set(SOURCES FileWriter.cpp FileLoader.cpp)

if(MY_FILE_LOADER_AS_SHARED)
    add_library(${LIB_NAME} SHARED ${SOURCES})
else()
    add_library(${LIB_NAME} STATIC ${SOURCES})
endif()

target_include_directories(${LIB_NAME} INTERFACE .)

