cmake_minimum_required(VERSION 3.7.0)

project(interactive_daemon)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#build daemon
add_executable(daemon "")
target_sources(daemon
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/daemon.c
 )
install(TARGETS daemon DESTINATION bin)

#built_button_process
add_executable(launch "")

target_sources(launch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/launch.c
  )
  
install(TARGETS launch DESTINATION bin)
