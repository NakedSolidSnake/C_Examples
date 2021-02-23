cmake_minimum_required(VERSION 3.7.0)

project(launcher)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX "/home/$ENV{USER}")
set(CMAKE_BUILD_TYPE Debug)







if(${ARCH} STREQUAL "THREAD")

  add_definitions(-DTHREAD)

  add_library(task "")
  target_sources(task
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks/tasks.c
  )
  target_include_directories(task 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks
  )  

  message("-- Created ${ARCH} compilation.")  
  add_executable(thread "")
  target_link_libraries(thread PUBLIC task pthread)
  target_sources(thread
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/thread/main.c
  )
  target_include_directories(thread 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks
  )


elseif (${ARCH} STREQUAL "PROCESS")

  add_definitions(-DPROCESS)
  message("-- Created ${ARCH} compilation.")  

  add_executable(process "")
  target_sources(process
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/process/main.c
  )
  target_include_directories(process 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks
  )

  add_executable(task "")
  target_sources(task
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks/tasks.c
  )
  target_include_directories(task 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tasks
  )
 

endif()