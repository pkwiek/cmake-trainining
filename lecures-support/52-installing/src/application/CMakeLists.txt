set(APP_NAME Application)

project(${APP_NAME})

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE JsonCameraDataParser)
target_link_libraries(${APP_NAME} PRIVATE FileOperations)

install(TARGETS ${APP_NAME}
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)