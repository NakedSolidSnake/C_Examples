cmake_minimum_required(VERSION 3.7.0)

project(Microservices)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

#build track
add_executable(track "")
# target_link_libraries(track PUBLIC pthread)
target_link_libraries(track PUBLIC glut GLU GL)

target_sources(track
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
  ${CMAKE_CURRENT_LIST_DIR}/src/graphics.c
  )

target_include_directories(track
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
)
install(TARGETS track DESTINATION bin)

