cmake_minimum_required(VERSION 3.22)
project(FunctionsTask LANGUAGES CXX)

function(CreateLibrary LIB_NAME LIB_TYPE LOG SOURCES)
    if (LOG)
        message("Creating library: ${LIB_NAME} from files:")
    endif ()
    add_library(${LIB_NAME} ${LIB_TYPE} ${SOURCES})
endfunction()

set(SRC_FILES main.cpp Class.cpp OtherClass.cpp)

# there is bug here, but where?
CreateLibrary(MyLib STATIC FALSE ${SRC_FILES})