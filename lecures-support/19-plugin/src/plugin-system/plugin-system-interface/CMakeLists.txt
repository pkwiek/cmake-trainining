set(LIB_NAME PluginSystemInterface)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

add_library(SevenIDE::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} INTERFACE SevenIDE::StandardLibrary)
target_link_libraries(${LIB_NAME} INTERFACE SevenIDE::EntityComponents)
target_link_libraries(${LIB_NAME} INTERFACE SevenIDE::Graphics2D)

target_compile_options(${LIB_NAME} PRIVATE -fPIC)