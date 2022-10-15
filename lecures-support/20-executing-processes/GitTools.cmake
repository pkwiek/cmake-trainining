find_package(Git REQUIRED)

add_custom_target(PrintCurrentGitBranch
        COMMAND "${GIT_EXECUTABLE}" branch --show-current
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

add_custom_target(PrintCurrentRevision
        COMMAND "${GIT_EXECUTABLE}" rev-parse HEAD
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# to fail compilation attach this target
# or use add_custom_command(TARGET your-target PRE_BUILD CheckIfRepositoryIsClean)
add_custom_target(CheckIfRepositoryIsClean
        COMMAND "${GIT_EXECUTABLE}" diff HEAD --quiet --exit-code
        COMMENT "Checking if repository is clean. If it fails commit or stash your changes"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# usage:
# GetCurrentRevision(MY_VARIABLE)
# message("Revision is: ${MY_VARIABLE})
function(GetCurrentRevision GIT_REVISION_OUT)
    execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse HEAD
            OUTPUT_VARIABLE GIT_REVISION
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
    string(STRIP ${GIT_REVISION} GIT_REVISION)
    set(${GIT_REVISION_OUT} ${GIT_REVISION} PARENT_SCOPE)
endfunction()