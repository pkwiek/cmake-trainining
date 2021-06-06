cmake_minimum_required(VERSION 3.16)
project(FunctionsTask)

function(CreateLibrary LIB_NAME LIB_TYPE LOG FIRST_SOURCE_FILE)
    if (LOG)
        message("Creating library: ${LIB_NAME}")
    endif ()
    add_library(${LIB_NAME} ${LIB_TYPE} ${FIRST_SOURCE_FILE} ${ARGN})
endfunction()

set(SRC_FILES main.cpp OtherClass.cpp MyClass.cpp)

CreateLibrary(MyLib STATIC TRUE ${SRC_FILES})
