set(LINARO_URL "https://releases.linaro.org/components/toolchain/binaries/5.4-2017.05/arm-linux-gnueabihf/gcc-linaro-5.4.1-2017.05-x86_64_arm-linux-gnueabihf.tar.xz")
set(LINARO_SYSROOT_URL "https://releases.linaro.org/components/toolchain/binaries/5.4-2017.05/arm-linux-gnueabihf/sysroot-glibc-linaro-2.21-2017.05-arm-linux-gnueabihf.tar.xz")

function(GetArchiveFileName OUTPUT_VAR FILE_PATH)
    if (FILE_PATH MATCHES ".tar.gz"
            OR FILE_PATH MATCHES "tar.xz")
        get_filename_component(FILE_NAME ${FILE_PATH} NAME_WLE)
        get_filename_component(FILE_NAME ${FILE_NAME} NAME_WLE)
    elseif (FILE_PATH MATCHES ".tar"
            OR FILE_PATH MATCHES ".zip")
        get_filename_component(FILE_NAME ${FILE_NAME} NAME_WLE)
    else ()
        message(FATAL_ERROR "Not supported archive format")
    endif ()
    set(${OUTPUT_VAR} ${FILE_NAME} PARENT_SCOPE)
endfunction()

GetArchiveFileName(GCC_LINARO_ARCHIVE_EXTRACTED_DIR ${LINARO_URL})
GetArchiveFileName(SYSROOT_ARCHIVE_EXTRACTED_DIR ${LINARO_SYSROOT_URL})

set(DOWNLOAD_DIR "${CMAKE_SOURCE_DIR}/tools")
set(LINARO_DIR "${DOWNLOAD_DIR}/${GCC_LINARO_ARCHIVE_EXTRACTED_DIR}")

# we use macro here instead of function to early exit from "DownloadLinaro" function by calling return
macro(DownloadAndExtractFile URL)
    get_filename_component(ARCHIVE_FILENAME ${URL} NAME)

    GetArchiveFileName(ARCHIVE_EXTRACTED_DIR ${URL})

    set(DOWNLOAD_DESTINATION "${DOWNLOAD_DIR}/${ARCHIVE_FILENAME}")

    if (EXISTS ${DOWNLOAD_DESTINATION})
        message(STATUS "${ARCHIVE_EXTRACTED_DIR} is during download in other CMake configuration.")
        return()
    endif ()

    message("Downloading to ${DOWNLOAD_DESTINATION}. Please wait...")
    file(DOWNLOAD ${URL} "${DOWNLOAD_DESTINATION}" SHOW_PROGRESS)
    file(ARCHIVE_EXTRACT INPUT ${DOWNLOAD_DESTINATION} DESTINATION ${DOWNLOAD_DIR})
endmacro()

function(DownloadLinaro)
    if (EXISTS ${LINARO_DIR})
        message("Linaro compiler already downloaded: ${LINARO_DIR}")
        return()
    endif ()

    DownloadAndExtractFile(${LINARO_URL})
    DownloadAndExtractFile(${LINARO_SYSROOT_URL})

    if (EXISTS "${DOWNLOAD_DIR}/${SYSROOT_ARCHIVE_EXTRACTED_DIR}")
        file(RENAME "${DOWNLOAD_DIR}/${ARCHIVE_EXTRACTED_DIR}" "${DOWNLOAD_DIR}/${GCC_LINARO_ARCHIVE_EXTRACTED_DIR}/sysroot")
    endif ()
endfunction()

DownloadLinaro()

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT ${LINARO_DIR}/sysroot)
set(CMAKE_C_COMPILER ${LINARO_DIR}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${LINARO_DIR}/bin/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)