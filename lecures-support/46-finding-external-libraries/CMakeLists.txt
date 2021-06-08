cmake_minimum_required(VERSION 3.19)

set(APP_NAME QtApplication)

project(QtApplication)

find_package(Qt5 5.15.2 EXACT COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PRIVATE Qt5::Widgets)