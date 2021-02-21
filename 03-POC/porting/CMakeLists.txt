cmake_minimum_required(VERSION 3.0.2)

project(blinkled VERSION 1.0.0)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

option(PC "Compiling to pc target" OFF)
option(RASPBERRY "Compiling to raspberry target" ON)

add_subdirectory(./arch)

# application
add_executable(app "")

target_link_libraries(app PUBLIC led)
target_sources(app 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/application.c
  )
target_include_directories(app 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )
