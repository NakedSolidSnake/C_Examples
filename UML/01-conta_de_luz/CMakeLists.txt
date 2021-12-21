cmake_minimum_required(VERSION 3.7.0)

project(bill)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(bill "")
# target_link_libraries(bill PUBLIC ${CMAKE_CURRENT_LIST_DIR}/libjsmn.a)
target_sources(bill
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
  ${CMAKE_CURRENT_LIST_DIR}/src/eletric_bill.c
  ${CMAKE_CURRENT_LIST_DIR}/src/eletric_bills_control.c
  )
target_include_directories(bill 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src
  )
