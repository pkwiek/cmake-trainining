cmake_minimum_required(VERSION 3.22)

project(variables)

#set(LIST_VARIABLE A B C)

#list(APPEND LIST_VARIABLE D)

message("LIST_VARIABLE value: ${LIST_VARIABLE}")

if (DEFINED LIST_VARIABLE)
    message("Is defined")
else()
    message("Is not defined")
endif()
