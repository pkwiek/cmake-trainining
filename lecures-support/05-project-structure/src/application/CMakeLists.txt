set(APP_NAME Application)

project(${APP_NAME})

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE App::JsonCameraDataParser)
target_link_libraries(${APP_NAME} PRIVATE App::FileOperations)