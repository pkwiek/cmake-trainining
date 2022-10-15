cmake_minimum_required(VERSION 3.22)

project(InstallableLibrary)

option(FILE_LOADER_BUILD_SHARED "If ON builds dynamic library" ON)
option(FILE_LOADER_BUILD_STATIC "If ON builds static library" ON)

set(DYNAMIC_LIB_NAME InstallableDynamicLibrary)
set(STATIC_LIB_NAME InstallableStaticLibrary)

set(SOURCE_FILES FileLoader.cpp FileWriter.cpp)
set(HEADER_FILES_TO_INSTALL FileWriter.h FileLoader.h)

if (${FILE_LOADER_BUILD_SHARED})
    add_library(${DYNAMIC_LIB_NAME} SHARED ${SOURCE_FILES})
    #    target_include_directories(${DYNAMIC_LIB_NAME} INTERFACE .)
    target_include_directories(${DYNAMIC_LIB_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                                                             $<INSTALL_INTERFACE:include/file-loader>)
    set_target_properties(${DYNAMIC_LIB_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES_TO_INSTALL}")
endif ()

if (${FILE_LOADER_BUILD_STATIC})
    add_library(${STATIC_LIB_NAME} STATIC ${SOURCE_FILES})
    #    target_include_directories(${STATIC_LIB_NAME} INTERFACE .)
    target_include_directories(${STATIC_LIB_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                                                            $<INSTALL_INTERFACE:include/file-loader>)
    set_target_properties(${STATIC_LIB_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES_TO_INSTALL}")
endif ()

install(TARGETS ${DYNAMIC_LIB_NAME} ${STATIC_LIB_NAME}
        EXPORT FileLoaderTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION lib
        OBJECTS DESTINATION ext
        PUBLIC_HEADER DESTINATION include/file-loader)

install(EXPORT FileLoaderTargets
        NAMESPACE FileLoader::
        FILE fileloader-config.cmake
        DESTINATION lib/cmake/FileLoader)

add_custom_target(RunInstall
    COMMAND ${CMAKE_COMMAND} --build . --target install
    COMMENT "Running custom install command. Please wait..."
        )