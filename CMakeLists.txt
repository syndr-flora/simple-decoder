cmake_minimum_required(VERSION 3.15)

project(simple_decoder
    VERSION
        0.1
    DESCRIPTION
        "Sample C Implementation of AV1 Library"
    LANGUAGES
        C
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(dav1d)

add_subdirectory(src)

