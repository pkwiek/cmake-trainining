set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT "/home/nobleprog/tools/compilers/gcc-linaro/sysroot-glibc-linaro-2.21-2017.05-arm-linux-gnueabihf")

set(LINARO_DIR "/home/nobleprog/tools/compilers/gcc-linaro/gcc-linaro-5.4.1-2017.05-x86_64_arm-linux-gnueabihf")
set(CMAKE_C_COMPILER ${LINARO_DIR}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${LINARO_DIR}/bin/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)