set(LIB_NAME simple-server)

project(${LIB_NAME})

set(MY_APP_COST "EXPENSIVE" CACHE STRING "Application type")
set_property(CACHE MY_APP_COST PROPERTY STRINGS TEST FREE EXPENSIVE)

set(SOURCES SimpleServerAddressProvider.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})

if(MY_APP_COST STREQUAL "TEST")
    target_compile_definitions(${LIB_NAME} PRIVATE -DMY_ADDRESS=\"https://test.server.com\")
elseif(MY_APP_COST STREQUAL "FREE")
    target_compile_definitions(${LIB_NAME} PRIVATE -DMY_ADDRESS=\"https://slow.server.com\")
elseif(MY_APP_COST STREQUAL "EXPENSIVE")
    target_compile_definitions(${LIB_NAME} PRIVATE -DMY_ADDRESS=\"https://slightlyfaster.server.com\")
else()
    message(FATAL_ERROR "Application type not selected")
endif()

target_link_libraries(${LIB_NAME} PUBLIC server-interface)

target_include_directories(${LIB_NAME} INTERFACE .)
