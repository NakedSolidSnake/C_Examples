cmake_minimum_required(VERSION 3.2)

project(Tank)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)




# Tank
add_executable(tank "")
target_link_libraries(tank PUBLIC pthread paho-mqtt3c)

target_sources(tank 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/main.c
  )

target_include_directories(tank 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )