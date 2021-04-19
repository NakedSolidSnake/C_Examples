cmake_minimum_required(VERSION 3.7.0)

project(2D_Shoot)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(shooter "")
target_link_libraries(shooter PUBLIC SDL2)

target_sources(shooter
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/draw.c
  ${CMAKE_CURRENT_LIST_DIR}/init.c
  ${CMAKE_CURRENT_LIST_DIR}/input.c
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  )

target_include_directories(shooter
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )

install(TARGETS shooter DESTINATION bin)

