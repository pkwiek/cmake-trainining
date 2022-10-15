set(LIB_NAME Objects2DPlugin)

aux_source_directory(. SRC_FILES)

include(SevenidePlugin)

sevenide_add_plugin(${LIB_NAME} ${SRC_FILES})
add_library(SevenIDE::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} PRIVATE SevenIDE::PluginSystemInterface)

if (MSVC)
    target_compile_definitions(${LIB_NAME} INTERFACE "SEVENIDE_OBJECT2D_API=__declspec(dllimport)")
    target_compile_definitions(${LIB_NAME} PRIVATE "SEVENIDE_OBJECT2D_API=__declspec(dllexport)")
else ()
    target_compile_definitions(${LIB_NAME} PUBLIC "SEVENIDE_OBJECT2D_API=")

    target_compile_options(${LIB_NAME} PRIVATE -fPIC)
endif ()

