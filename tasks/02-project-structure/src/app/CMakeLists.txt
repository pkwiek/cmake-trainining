project(application LANGUAGES CXX)

set(SOURCES main.cpp)

add_executable(application ${SOURCES})

target_link_libraries(application PRIVATE
        json-parser
        file-loader
        simple-server
        )