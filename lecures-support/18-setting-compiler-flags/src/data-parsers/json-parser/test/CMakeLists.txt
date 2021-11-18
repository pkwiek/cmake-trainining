set(TEST_NAME JsonParserTests)

project(${TEST_NAME})

aux_source_directory(. TEST_FILES)

add_executable(${TEST_NAME} ${TEST_FILES})

target_link_libraries(${TEST_NAME} PRIVATE gmock gmock_main)
target_link_libraries(${TEST_NAME} PRIVATE JsonCameraDataParser)