cmake_minimum_required(VERSION 3.9.0)

project(kill_proj)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_library(common "")

target_sources(common 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/common.c
  )
target_include_directories(common PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)

#process 
add_executable(process "")
target_link_libraries(process PUBLIC common)
target_include_directories(process PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)
target_sources(process
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/process.c
  )
install(TARGETS process DESTINATION bin)

#process
add_executable(control "")
target_link_libraries(control PUBLIC common)
target_include_directories(control PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)
target_sources(control
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/control.c
  )
install(TARGETS control DESTINATION bin)

#launch
add_executable(launch "")
target_link_libraries(launch PUBLIC common)
target_include_directories(launch PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)
target_sources(launch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/launch.c
  )
install(TARGETS launch DESTINATION bin)

