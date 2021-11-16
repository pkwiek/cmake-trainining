cmake_minimum_required(VERSION 3.16)
project(FunctionExtraParameters)

function(CreateLibrary)
    set(OPTIONS LOG)
    set(SINGLE_ARG_PARAMS TYPE NAME)
    set(MULTI_ARG_PARAMS SOURCES)

    cmake_parse_arguments(YOUR_PREFIX "${OPTIONS}"
                                      "${SINGLE_ARG_PARAMS}"
                                      "${MULTI_ARG_PARAMS}"
                                      "${ARGN}")
    if (NOT YOUR_PREFIX_SOURCES)
        message(FATAL_ERROR "To you need to provide SOURCES")
    elseif (NOT YOUR_PREFIX_NAME)
        message(FATAL_ERROR "To you need to provide LIB_NAME")
    elseif (YOUR_PREFIX_LOG)
        message("Creating library: ${YOUR_PREFIX_NAME}")
    endif ()
    add_library(${YOUR_PREFIX_NAME} ${YOUR_PREFIX_TYPE} ${YOUR_PREFIX_SOURCES})
endfunction()

set(SRC_FILES main.cpp myClass.cpp otherClass.cpp)

CreateLibrary(
        TYPE SHARED
        SOURCES ${SRC_FILES}
        NAME MyLib
        LOG
)