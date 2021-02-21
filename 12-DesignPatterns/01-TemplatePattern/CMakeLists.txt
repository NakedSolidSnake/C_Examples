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



add_executable(template_demo "")
target_sources(template_demo
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/template.c
  ${CMAKE_CURRENT_LIST_DIR}/src/soccer.c
  ${CMAKE_CURRENT_LIST_DIR}/src/voleyball.c
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  )
target_include_directories(template_demo 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include  
  )
install(TARGETS template_demo DESTINATION bin)