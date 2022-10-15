cmake_minimum_required(VERSION 3.22)

project(ExecutingProcess)

include(GitTools.cmake)

GetCurrentRevision(REVISION)

message(STATUS "Current git revision is: ${REVISION}")