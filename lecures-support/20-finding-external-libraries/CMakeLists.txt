cmake_minimum_required(VERSION 3.16)

set(APP_NAME Application)

project(${APP_NAME})

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PRIVATE OpenGL::GL)