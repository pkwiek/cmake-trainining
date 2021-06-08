cmake_minimum_required(VERSION 3.16)
project(StructuredProjectExample LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN/")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(src)

add_custom_target(CreateInstaller
        COMMAND ${CMAKE_COMMAND} --build . --target install
        COMMENT "Running install target"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})