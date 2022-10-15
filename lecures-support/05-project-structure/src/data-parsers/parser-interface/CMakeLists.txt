set(LIB_NAME CameraDataParserInterface)

project(${LIB_NAME})

add_library(${LIB_NAME} INTERFACE)
add_library(App::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} INTERFACE .)