cmake_minimum_required(VERSION 3.7.0)

project(hexagon_arch)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(hexagon "")
# target_link_libraries(bill PUBLIC ${CMAKE_CURRENT_LIST_DIR}/libjsmn.a)
target_sources(hexagon
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/domain/model/product.c
  ${CMAKE_CURRENT_LIST_DIR}/domain/services/service.c
  ${CMAKE_CURRENT_LIST_DIR}/adapters/repository/product_repository.c
  ${CMAKE_CURRENT_LIST_DIR}/adapters/controller/product_controller.c
  ${CMAKE_CURRENT_LIST_DIR}/adapters/controller/udp/udp.c
  )
target_include_directories(hexagon 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/domain/ports
  ${CMAKE_CURRENT_LIST_DIR}/domain/services
  ${CMAKE_CURRENT_LIST_DIR}/domain/model
  ${CMAKE_CURRENT_LIST_DIR}/adapters/repository
  ${CMAKE_CURRENT_LIST_DIR}/adapters/controller
  ${CMAKE_CURRENT_LIST_DIR}/adapters/controller/udp
  )
