cmake_minimum_required(VERSION 3.7.0)

project(webserver)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


add_library(jsmn "")
target_link_libraries(jsmn "")
target_sources(jsmn 
  PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/lib/jsmn.c 
  )
target_include_directories(jsmn 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
  

#------------------------------------------------------------------------------------------------------
#rover_server 
#------------------------------------------------------------------------------------------------------
add_executable(server "")
target_link_libraries(server PUBLIC  comm jsmn)
target_sources(server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/server.c
  )
target_include_directories(server 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib
  )

install(TARGETS server DESTINATION bin)

#------------------------------------------------------------------------------------------------------
#rover_client
#------------------------------------------------------------------------------------------------------
add_executable(client "")
target_sources(client
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/client.c
  )

install(TARGETS client DESTINATION bin)


#------------------------------------------------------------------------------------------------------
# client_demo
#------------------------------------------------------------------------------------------------------
add_executable(client_demo "")
target_link_libraries(client_demo PUBLIC  curl)
target_sources(client_demo
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/client_demo.c
  )

install(TARGETS client_demo DESTINATION bin)