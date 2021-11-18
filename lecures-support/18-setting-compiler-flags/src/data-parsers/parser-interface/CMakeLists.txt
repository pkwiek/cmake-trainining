set(LIB_NAME CameraDataParserInterface)

project(${LIB_NAME})

add_library(${LIB_NAME} INTERFACE)

target_include_directories(${LIB_NAME} INTERFACE .)