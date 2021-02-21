cmake_minimum_required(VERSION 3.09)

project(thread)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-Wall -std=c99")

add_executable(thread main.c)
target_link_libraries(thread pthread)
