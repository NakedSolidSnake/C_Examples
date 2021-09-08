cmake_minimum_required(VERSION 3.7.0)

project(Lista_Encadiada_Circular)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(lista_encadiada_circular "")
# target_link_libraries(csp_client PUBLIC curl)

target_sources(lista_encadiada_circular
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/lista_encadiada_circular.c    
  )

target_include_directories(lista_encadiada_circular
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )

install(TARGETS lista_encadiada_circular DESTINATION bin)

