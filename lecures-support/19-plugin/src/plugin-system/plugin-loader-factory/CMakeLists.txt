set(LIB_NAME PluginLoaderFactory)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)
add_library(SevenIDE::${LIB_NAME} ALIAS ${LIB_NAME})

message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

target_link_libraries(${LIB_NAME} PUBLIC SevenIDE::PluginSystemInterface)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(${LIB_NAME} PRIVATE SEVENIDE_LINUX)
    target_link_libraries(${LIB_NAME} PRIVATE SevenIDE::LinuxPluginSystem)
#elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
else()
    message(FATAL_ERROR "Platform \"CMAKE_SYSTEM_NAME\" not supported")
endif()