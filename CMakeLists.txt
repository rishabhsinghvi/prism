cmake_minimum_required(VERSION 3.2)

#if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
#    message(FATAL_ERROR "Attempting an in-source build. An in-source build is generally not recommended. Consider using a separate build directory.")
#endif()

project(prism VERSION 1.0 DESCRIPTION "Prism Physics Library" LANGUAGES C)

set(CMAKE_C_STANDARD 11)

# Default build type is a static library
option(PRISM_BUILD_SHARED "Build a shared library" OFF)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Set the build type (Release/Debug)")

if(PRISM_BUILD_SHARED)
    message("Building a shared library...")
    set(BUILD_TYPE SHARED)
    add_definitions(-DPRISM_BUILD_SHARED)
else()
    message("Building a static library...")
    set(BUILD_TYPE STATIC)
endif()

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.c)

add_library(prism ${BUILD_TYPE} ${SOURCE_FILES})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Building a release build...")
    target_compile_options(prism PRIVATE -O3)
else()
    message("Building a debug build..")
    target_compile_options(prism PRIVATE -g -O0)
endif()

target_include_directories(prism PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_compile_options(prism PRIVATE -Wall -pedantic -Wextra -Wno-switch -Wno-newline-eof)