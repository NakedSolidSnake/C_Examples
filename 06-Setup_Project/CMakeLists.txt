cmake_minimum_required(VERSION 3.7.0)

project(Setup_Project)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(setup_project "")
# target_link_libraries(setup_project PUBLIC pthread)

target_sources(setup_project
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
  )

install(TARGETS setup_project DESTINATION bin)

