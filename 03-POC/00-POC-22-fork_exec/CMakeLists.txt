cmake_minimum_required (VERSION 3.09)

project(exec)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

#exec
add_executable(fork_exec "")
target_sources(fork_exec 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/fork_exec/fork_exec.c 
  )
install(TARGETS fork_exec DESTINATION bin)

#hello
add_executable(hello "")
target_sources(hello 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/hello/hello.c 
  )
install(TARGETS hello DESTINATION bin)
