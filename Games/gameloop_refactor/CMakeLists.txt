cmake_minimum_required(VERSION 3.7.0)

project(Game)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

# Specify the cross compiler
#SET(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


add_executable(game "")
target_link_libraries(game PUBLIC SDL2 SDL2_ttf)
target_sources(game
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c  
  ${CMAKE_CURRENT_LIST_DIR}/src/game.c 
  )
target_include_directories(game 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )

install(TARGETS game DESTINATION bin)

file(COPY fonts/Crazy-Pixel.ttf DESTINATION bin)