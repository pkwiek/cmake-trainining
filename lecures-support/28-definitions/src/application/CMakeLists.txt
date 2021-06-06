set(APP_NAME Application)

project(${APP_NAME})

set(APP_SHOULD_BE_NICE "OFF" CACHE BOOL "We are nice")
set(APP_SHOULD_CONNECT "ON" CACHE BOOL "Connection")

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE JsonCameraDataParser)
target_link_libraries(${APP_NAME} PRIVATE FileOperations)

target_compile_definitions(${APP_NAME} PUBLIC APP_VERSION="${CMAKE_PROJECT_VERSION}")
target_compile_definitions(${APP_NAME} PUBLIC APP_BUILD_TYPE="$<CONFIG>")

target_compile_definitions(${APP_NAME} PUBLIC APP_IS_NICE=$<BOOL:$CACHE{APP_SHOULD_BE_NICE}>)

if ($CACHE{APP_SHOULD_CONNECT})
    target_compile_definitions(${APP_NAME} PUBLIC APP_ONLINE=$<BOOL:$CACHE{APP_SHOULD_CONNECT}>)
endif ()

