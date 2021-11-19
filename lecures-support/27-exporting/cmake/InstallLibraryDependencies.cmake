function(InstallLibraryDependency LIB_PATH INSTALL_DESTINATION)
    install(CODE
            "file(GET_RUNTIME_DEPENDENCIES
            RESOLVED_DEPENDENCIES_VAR _RESOLVED_DEPENDENCIES
            UNRESOLVED_DEPENDENCIES_VAR unresolved_deps
            LIBRARIES  ${LIB_PATH}
            POST_EXCLUDE_REGEXES \".*WINDOWS\\\\\\\\system32.*\"                 )
        message(\"Scanning dependency of ${LIB_PATH} \")
        foreach(_DEPENDENCY_FILE \${_RESOLVED_DEPENDENCIES})
            message(\"Installing dependency ${LIB_PATH}: \${_DEPENDENCY_FILE} \")
            file(INSTALL DESTINATION \"\${CMAKE_INSTALL_PREFIX}/${INSTALL_DESTINATION}\"
                         TYPE FILE
                         FILES \"\${_DEPENDENCY_FILE}\")
        endforeach()")
endfunction()