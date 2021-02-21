cmake_minimum_required(VERSION 3.02)

project(fork)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_FLAGS "-Wall -std=c99")
set(CMAKE_BUILD_TYPE Debug)

add_executable(fork fork.c)

