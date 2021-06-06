# file FindMyCalculator.cmake

find_path(MyCalculator_INCLUDE_DIR 
    NAMES MyCalculator.h
    PATH_SUFIXES MyCalculator)

find_library(MyCalculator_LIBRARY
    NAMES MyCalculator MyCalc)
	
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MyCalculator
    REQUIRED_VARS MyCalculator_INCLUDE_DIR MyCalculator_LIBRARY

if (NOT TARGET MyCalculator::MyCalculator)
    add_library(MyCalculator::MyCalculator STATIC IMPORTED)
    set_target_properties(MyCalculator::MyCalculator PROPERTIES
                 IMPORTED_LOCATION ${MyCalculator_LIBRARY}
                 INTERFACE_INCLUDE_DIRECTORIES ${MyCalculator_INCLUDE_DIR})
endif()
unset(MyCalculator_INCLUDE_DIR)
unset(MyCalculator_LIBRARY)

