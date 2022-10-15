set(APP_NAME Application)

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE SevenIDE::PluginLoaderFactory)

include(TargetPluginDependency)

target_plugin_dependency(${APP_NAME}
        PLUGINS SevenIDE::Objects2DPlugin
                SevenIDE::OpenGlGraphics
        DEPLOY_PATH plugins)