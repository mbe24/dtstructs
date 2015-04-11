cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_COMPILER "clang++")

project (dtstructs)

set (EXTRA_COMPILE_FLAGS "-std=c++1y -Wall -Werror")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")

#set (EXTRA_LINK_FLAGS    "-stdlib=libc++")
#set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${EXTRA_LINK_FLAGS}")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../target/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../target/lib)

set (INCLUDE_DIR ${CMAKE_BINARY_DIR}/../include)
include_directories(${INCLUDE_DIR})

add_subdirectory (src)