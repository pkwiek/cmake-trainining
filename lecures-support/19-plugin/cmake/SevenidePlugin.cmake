function(sevenide_add_plugin TARGET_NAME)
    add_library(${TARGET_NAME} MODULE ${ARGN})

    add_dependencies(${TARGET_NAME} PluginValidator)

    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMENT "Verifying plugin"
            COMMAND PluginValidator $<TARGET_FILE:${TARGET_NAME}>
            )

    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${TARGET_NAME} PRIVATE -fPIC)
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(${TARGET_NAME} PRIVATE -fPIC)
    endif()
endfunction()
