add_subdirectory(plugin-system-interface)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
add_subdirectory(linux-plugin-system)
endif()

add_subdirectory(plugin-loader-factory)

add_subdirectory(plugin-validator)