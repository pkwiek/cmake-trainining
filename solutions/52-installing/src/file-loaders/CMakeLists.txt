set(LIB_NAME FileOperations)

project(${LIB_NAME})

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} SHARED ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

install(TARGETS ${LIB_NAME}
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION bin)

