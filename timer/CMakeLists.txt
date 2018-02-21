cmake_minimum_required (VERSION 3.5)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_C_COMPILER "/usr/bin/clang")
set (CMAKE_C_FLAGS "-std=c11 -Os -g3 -Wall -Wextra -Wshadow")

include_directories (
	./
)

file (GLOB SRCS
	timer.c
	timer_test.c
)

project (timer)
add_executable (timer ${SRCS})
target_link_libraries (timer rt)
