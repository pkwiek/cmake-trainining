set(LIB_NAME simple-server)

project(${LIB_NAME})

set(SOURCES SimpleServerAddressProvider.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})

target_link_libraries(${LIB_NAME} PUBLIC server-interface)

target_include_directories(${LIB_NAME} INTERFACE .)
