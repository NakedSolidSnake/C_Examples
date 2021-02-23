cmake_minimum_required(VERSION 3.2)

project(WebServer)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)


add_executable(server "")

target_sources(server 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/server.c
  )

target_include_directories(server 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )


add_executable(client "")

target_sources(client 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/client.c
  )

target_include_directories(client 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )