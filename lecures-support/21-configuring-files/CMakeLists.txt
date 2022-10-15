cmake_minimum_required(VERSION 3.22)
project(ProjectWithDoxygenExample LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(external EXCLUDE_FROM_ALL)
add_subdirectory(src)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYFILE_PATH ${CMAKE_BINARY_DIR}/Doxyfile)
#    configure_file(${CMAKE_SOURCE_DIR}/Doxyfile-alternative.in ${DOXYFILE_PATH})
    configure_file(${CMAKE_SOURCE_DIR}/Doxyfile.in ${DOXYFILE_PATH})

    message(STATUS "Doxyfile prepared: ${DOXYFILE_PATH}")

    add_custom_target(GenerateDoc
            ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_PATH}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating documentation"
            VERBATIM)
else()
    message(STATUS "Doxygen not found")
endif ()