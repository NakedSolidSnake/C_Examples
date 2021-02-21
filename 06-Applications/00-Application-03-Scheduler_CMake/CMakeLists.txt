cmake_minimum_required(VERSION 2.8.9)
project(scheduler)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(sched ${SOURCES})
target_link_libraries(sched pthread)
