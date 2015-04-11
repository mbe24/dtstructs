cmake_minimum_required (VERSION 2.8)
#set (CMAKE_CXX_COMPILER "clang++")
project (dtstructs CXX)

include(CheckCXXCompilerFlag)

set (EXTRA_COMPILE_FLAGS "-Wall -Werror")

CHECK_CXX_COMPILER_FLAG(-std=c++14 HAS_CXX_14)
CHECK_CXX_COMPILER_FLAG(-std=c++1y HAS_CXX_1Y)
if (HAS_CXX_14)
    set(EXTRA_COMPILE_FLAGS "${EXTRA_COMPILE_FLAGS} -std=c++14")
elseif(HAS_CXX_1Y)
    set(EXTRA_COMPILE_FLAGS "${EXTRA_COMPILE_FLAGS} -std=c++1y")
else()
  message(STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++14 support!")
endif()


set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")

#set (EXTRA_LINK_FLAGS    "-stdlib=libc++")
#set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${EXTRA_LINK_FLAGS}")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../target/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../target/lib)

set (INCLUDE_DIR ${CMAKE_BINARY_DIR}/../include)
include_directories(${INCLUDE_DIR})

add_subdirectory (src)