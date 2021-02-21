cmake_minimum_required(VERSION 3.7.0)

project(server)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_library(common "")
target_sources(common
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/common.c
  )
target_include_directories(common
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
)

add_executable(sockpair "")
target_link_libraries(sockpair PUBLIC common)
target_sources(sockpair
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/chapter01/socketpair_ex.c
  )
target_include_directories(sockpair
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
)
