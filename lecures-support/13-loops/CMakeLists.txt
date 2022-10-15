cmake_minimum_required(VERSION 3.22)
project(Loops)

list(APPEND ENGLISH one two three four five)
list(APPEND POLISH jeden dwa trzy cztery)

foreach(WORD IN LISTS ENGLISH POLISH)
    message(STATUS "Word: ${WORD}")
endforeach()

message("============================================")

foreach(WORD IN ZIP_LISTS ENGLISH POLISH)
    message(STATUS "EN=${WORD_0}, PL=${WORD_1}")
endforeach()

message("============================================")

foreach(EN_WORD PL_WORD IN ZIP_LISTS ENGLISH POLISH)
    message(STATUS "EN=${EN_WORD}, PL=${PL_WORD}")
endforeach()