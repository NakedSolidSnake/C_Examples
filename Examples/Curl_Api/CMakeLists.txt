cmake_minimum_required(VERSION 3.7.0)

project(CURL_API)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(curl_api "")
target_link_libraries(curl_api PUBLIC curl)

target_sources(curl_api
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/csp_client.c  
  )

target_include_directories(curl_api
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )

install(TARGETS curl_api DESTINATION bin)

