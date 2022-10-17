set(LIB_NAME json-parser)

project(${LIB_NAME})

set(SOURCES JsonCameraDataParser.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})

target_link_libraries(${LIB_NAME} PUBLIC parser-interface)
target_link_libraries(${LIB_NAME} PRIVATE nlohmann_json nlohmann_json)

target_include_directories(${LIB_NAME} INTERFACE .)

add_subdirectory(test)