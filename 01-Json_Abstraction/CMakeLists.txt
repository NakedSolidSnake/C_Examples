cmake_minimum_required(VERSION 3.7.0)

project(Json)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_library(json)
target_link_libraries(json PUBLIC json-c)
target_sources(json
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/json.c
  )

target_include_directories(json 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib
  )

#build json
add_executable(json_exec "")

target_link_libraries(json_exec PUBLIC json)

target_sources(json_exec
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
  )

target_include_directories(json_exec 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib
  )

install(TARGETS json_exec DESTINATION bin)

file(COPY properties.json DESTINATION bin)