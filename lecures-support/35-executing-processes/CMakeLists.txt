cmake_minimum_required(VERSION 3.16)

project(ExecutingProcess)

include(GitTools.cmake)

GetCurrentRevision(REVISION)

message(STATUS "Current git revision is: ${REVISION}")