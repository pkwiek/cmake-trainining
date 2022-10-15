set(LIB_NAME JsonCameraDataParser)

project(${LIB_NAME})

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})
add_library(App::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} PUBLIC App::CameraDataParserInterface)
target_link_libraries(${LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(${LIB_NAME} INTERFACE .)

add_subdirectory(test)