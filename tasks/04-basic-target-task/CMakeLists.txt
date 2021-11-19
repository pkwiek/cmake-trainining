cmake_minimum_required(VERSION 3.16)
project(asd)

set(VARIABLE "FirstElement SecondElement")

if (${VARIABLE})
    message("Hello!")
else ()
    message("Hi!")
endif()