cmake_minimum_required(VERSION 3.7.0)

project(Lista_Duplamente_Encadiada)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(lista_duplamente_encadiada "")

target_sources(lista_duplamente_encadiada
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/lista_duplamente_encadiada.c    
  )

target_include_directories(lista_duplamente_encadiada
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )

install(TARGETS lista_duplamente_encadiada DESTINATION bin)

