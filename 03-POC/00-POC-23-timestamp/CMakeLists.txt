cmake_minimum_required (VERSION 3.09)

project(timestamp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

add_executable(timestamp "")
target_sources(timestamp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/timestamp.c 
  )
install(TARGETS timestamp DESTINATION bin)

