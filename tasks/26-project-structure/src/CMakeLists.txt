set(APP_NAME Application)
set(TEST_NAME Tests)

project(${APP_NAME})

aux_source_directory(. SRC_FILES)
add_executable(${APP_NAME} ${SRC_FILES})
target_link_libraries(${APP_NAME} PRIVATE nlohmann_json::nlohmann_json)

aux_source_directory(test TEST_FILES)
add_executable(${TEST_NAME} ${TEST_FILES} ${SRC_FILES})
target_link_libraries(${TEST_NAME} PRIVATE gmock gmock_main)