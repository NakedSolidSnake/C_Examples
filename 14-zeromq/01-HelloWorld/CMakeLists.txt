cmake_minimum_required(VERSION 3.7.0)

project(zmq_hello_world)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(zmq_hello_world_server "")
target_link_libraries(zmq_hello_world_server PUBLIC zmq)
target_sources(zmq_hello_world_server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/hello_world_server.c
  )

install(TARGETS zmq_hello_world_server DESTINATION bin)

add_executable(zmq_hello_world_client "")
target_link_libraries(zmq_hello_world_client PUBLIC zmq)
target_sources(zmq_hello_world_client
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/hello_world_client.c
  )

install(TARGETS zmq_hello_world_client DESTINATION bin)