cmake_minimum_required(VERSION 3.16)

project(CacheVariables)

option(MY_BUILD_TESTS "If ON then build tests" ON)

message("Reading by using CACHE: $CACHE{MY_BUILD_TESTS}") # ON
message("Reading like standard var: ${MY_BUILD_TESTS}")   # ON

set(MY_BUILD_TESTS OFF)

message("Reading again by using CACHE: $CACHE{MY_BUILD_TESTS}") # ON
message("Reading like standard var: ${MY_BUILD_TESTS}")         # OFF

# same as:
# set(BUILD_TESTS ON CACHE BOOL "If ON then build tests")

set(MY_CONFIGURATION_FILE "" CACHE FILEPATH "Some path to file")

set(MY_APP_TYPE "ENTERPRISE" CACHE STRING "Application type")
set_property(CACHE MY_APP_TYPE PROPERTY STRINGS TRIAL PERSONAL ENTERPRISE)

if ($CACHE{MY_BUILD_TESTS})
    message("We build tests")
else()
    message("We skip all tests")
endif()


