cmake_minimum_required (VERSION 3.5)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_C_COMPILER "/usr/bin/clang")
set (CMAKE_C_FLAGS "-std=c11 -Os -g3 -Wall -Wextra -Wshadow")


file (GLOB SRCS
	big_endian.c
)

project (big_endian)
add_executable (big_endian ${SRCS})
