cmake_minimum_required(VERSION 3.7.0)

project(Cube)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#build thread
add_executable(cube "")

target_link_libraries(cube PUBLIC m)

target_sources(cube
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/Cube.c
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  )

install(TARGETS cube DESTINATION bin)