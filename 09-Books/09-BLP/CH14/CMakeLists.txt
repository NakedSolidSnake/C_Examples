cmake_minimum_required(VERSION 3.9.0)

project(server_fifo)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set (CMAKE_C_FLAGS "-Wall -std=c99")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


#server 
add_executable(shm1 "")
target_sources(shm1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/shm1.c
  )
target_include_directories(shm1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS shm1 DESTINATION bin)

#client
add_executable(shm2 "")
target_sources(shm2
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/shm2.c
  )
target_include_directories(shm2
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS shm2 DESTINATION bin)


#server 
add_executable(msg1 "")
target_sources(msg1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/msg1.c
  )
target_include_directories(msg1
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS msg1 DESTINATION bin)

#client
add_executable(msg2 "")
target_sources(msg2
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/msg2.c
  )
target_include_directories(msg2
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
  )
install(TARGETS msg2 DESTINATION bin)
