cmake_minimum_required (VERSION 3.09)

project(exec)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

#exec
add_executable(exec "")
target_sources(exec 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/exec/exec.c 
  )
install(TARGETS exec DESTINATION bin)

#app
add_executable(app "")
target_sources(app 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/app/app.c 
  )
