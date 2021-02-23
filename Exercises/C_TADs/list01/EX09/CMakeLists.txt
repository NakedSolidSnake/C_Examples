cmake_minimum_required(VERSION 3.7.0)

project(Sphere)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#build thread
add_executable(sphere "")

target_link_libraries(sphere PUBLIC m)

target_sources(sphere
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/Sphere.c
  ${CMAKE_CURRENT_LIST_DIR}/TAD01.c
  )

install(TARGETS sphere DESTINATION bin)