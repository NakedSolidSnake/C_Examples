cmake_minimum_required (VERSION 3.09)

project(daemon)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(daemon "")
target_sources(daemon
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/daemon.c 
  )
install(TARGETS daemon DESTINATION bin)

