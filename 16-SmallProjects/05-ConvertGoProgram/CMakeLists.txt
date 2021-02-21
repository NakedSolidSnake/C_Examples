cmake_minimum_required(VERSION 3.2)

project(Convert)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)


add_executable(convert "")

target_sources(convert 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/main.c
    ${CMAKE_CURRENT_LIST_DIR}/routes/routes.c
  )

target_include_directories(convert 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )


