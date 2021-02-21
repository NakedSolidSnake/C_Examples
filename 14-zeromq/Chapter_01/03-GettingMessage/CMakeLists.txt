cmake_minimum_required(VERSION 3.7.0)

project(zmq_ex01)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(weatherUpdateClient "")
target_link_libraries(weatherUpdateClient PUBLIC zmq)
target_sources(weatherUpdateClient
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/weatherUpdateClient.c
  )

install(TARGETS weatherUpdateClient DESTINATION bin)

add_executable(weatherUpdateServer "")
target_link_libraries(weatherUpdateServer PUBLIC zmq)
target_sources(weatherUpdateServer
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/weatherUpdateServer.c
  )

install(TARGETS weatherUpdateServer DESTINATION bin)
