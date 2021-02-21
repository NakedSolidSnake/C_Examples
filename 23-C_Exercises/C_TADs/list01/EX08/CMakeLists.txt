cmake_minimum_required(VERSION 3.7.0)

project(Cilinder)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#build thread
add_executable(cilinder "")

target_link_libraries(cilinder PUBLIC m)

target_sources(cilinder
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/Cilinder.c
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  )

install(TARGETS cilinder DESTINATION bin)