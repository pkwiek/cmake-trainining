function(target_plugin_dependency TARGET_NAME)
    set(OPTIONS_LIST)
    set(SINGLE_ARG_LIST DEPLOY_PATH)
    set(MULTI_ARG_LIST PLUGINS)

    cmake_parse_arguments(PREFIX "${OPTIONS_LIST}" "${SINGLE_ARG_LIST}" "${MULTI_ARG_LIST}" "${ARGN}")

    if (NOT PREFIX_PLUGINS)
        message(FATAL_ERROR "Provide at least one plugin")
    endif()

    foreach(PLUGIN_TARGET_NAME IN LISTS PREFIX_PLUGINS)
        get_target_property(LIBRARY_TYPE ${PLUGIN_TARGET_NAME} TYPE)

        if(NOT LIBRARY_TYPE STREQUAL "MODULE_LIBRARY")
            message(FATAL_ERROR
                    "Target \"${PLUGIN_TARGET_NAME}\" is not a plugin \(it's type is \"${LIBRARY_TYPE}\"\). Use MODULE type")
        endif()

        add_dependencies(${TARGET_NAME} ${PREFIX_PLUGINS})

        set(DEPENDENCY_FILE "${TARGET_NAME}--${PLUGIN_TARGET_NAME}.txt")

        string(REPLACE "::" "--" DEPENDENCY_FILE ${DEPENDENCY_FILE})

        target_sources(${TARGET_NAME} PRIVATE ${DEPENDENCY_FILE})

        add_custom_command(OUTPUT ${DEPENDENCY_FILE}
                COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${TARGET_NAME}>/${PREFIX_DEPLOY_PATH}/
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:${PLUGIN_TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>/${PREFIX_DEPLOY_PATH}/$<TARGET_FILE_NAME:${PLUGIN_TARGET_NAME}>
                )
    endforeach()
endfunction()