set(APP_NAME "ClangTidyApplication")

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})
