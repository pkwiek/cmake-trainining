set(LIB_NAME parser-interface)

project(${LIB_NAME})

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE .)