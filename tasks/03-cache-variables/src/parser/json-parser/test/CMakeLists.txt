set(TEST_NAME json-parser-test)

project(${TEST_NAME})

set(SOURCES JsonParserTests.cpp)
add_executable(${TEST_NAME} ${SOURCES})

target_link_libraries(${TEST_NAME} PRIVATE gmock gmock_main)
target_link_libraries(${TEST_NAME} PRIVATE json-parser)