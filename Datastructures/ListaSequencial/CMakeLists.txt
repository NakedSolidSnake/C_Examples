cmake_minimum_required(VERSION 3.7.0)

project(Lista_Sequencial)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(lista_sequencial "")
# target_link_libraries(csp_client PUBLIC curl)

target_sources(lista_sequencial
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/lista_sequencial.c    
  )

target_include_directories(lista_sequencial
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )

install(TARGETS lista_sequencial DESTINATION bin)

