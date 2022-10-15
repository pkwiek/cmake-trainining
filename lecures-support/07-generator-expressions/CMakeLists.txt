cmake_minimum_required(VERSION 3.22)

project(GeneratorExpressions)

add_executable(GeneratorExpressions main.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:Clang>: -Werror -Wall>)
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:AppleClang>: -Werror -Wall>)
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:GNU>: -Werror -Wall>)
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MINGW>: -Werror -Wall>)
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MSVC>: /Wall /WX>)

target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:Clang>: -Werror -Wall>
                                              $<$<CXX_COMPILER_ID:AppleClang>: -Werror -Wall>
                                              $<$<CXX_COMPILER_ID:GNU>: -Werror -Wall>
                                              $<$<CXX_COMPILER_ID:MINGW>: -Werror -Wall>
                                              $<$<CXX_COMPILER_ID:MSVC>: /Wall /WX>)

# or, but OR expression cannot be split!
target_compile_options(${PROJECT_NAME} PUBLIC $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall>)
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MSVC>: /Wall /WX>)


# or, but OR expression cannot be split!
target_compile_options(${PROJECT_NAME} PUBLIC $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall>
                                              $<$<CXX_COMPILER_ID:MSVC>: /Wall /WX>)

