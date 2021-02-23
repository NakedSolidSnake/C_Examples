cmake_minimum_required(VERSION 3.7.0)

project(rover_rasp)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)



add_executable(wine "")
target_sources(wine
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/wine.c
  ${CMAKE_CURRENT_LIST_DIR}/main.c 
  )
target_include_directories(wine 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/  
  )
install(TARGETS wine DESTINATION bin)