cmake_minimum_required(VERSION 3.22)

project(FunctionsAndMacrosTest)

# uncomment this to display result
#return()

include(cmake/argumentsPrinters.cmake)

# to avoid relative path we can add path to directory with cmake files
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#include(argumentsPrinters)

message("---- same as expected arguments count ----")
DisplayFunctionArguments("A" "B")

# putting less than required parameters causes error
#DisplayFunctionArguments("A")

message("---- 2 extra arguments ----")
DisplayFunctionArguments(A B C D)

message("---- 1 extra list argument? ----")
set(LIST_VARIABLE C D)
DisplayFunctionArguments(A B ${LIST_VARIABLE})

message("---- real 1 extra list argument ----")
DisplayFunctionArguments(A B "${LIST_VARIABLE}")

message("--- Display by using foreach ---")
DisplayForEachArgument(ABC DFE XYZ)

message("--- Displaying only extra ---")
DisplayOnlyExtra(ABC DFE XYZ)
MacroDisplayOnlyExtra(ABC DFE XYZ)

message("--- Displaying only required ---")
DisplayOnlyRequired(ABC DFE XYZ)

message("--- Checking by function is DEFINED ---")
DisplayFirstParam(ABCD WXYZ XXX)
message("--- Checking by marco DEFINED ---")
MacroDisplayFirstParam(ABCD WXYZ XXX)
