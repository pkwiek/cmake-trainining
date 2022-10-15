set(APP_NAME "Application")

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})
