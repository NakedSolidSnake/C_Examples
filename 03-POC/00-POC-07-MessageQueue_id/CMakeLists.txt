cmake_minimum_required(VERSION 3.9)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_library(lib "")

target_sources(lib 
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/pqueue.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/people.c
  ${CMAKE_CURRENT_LIST_DIR}/lib/src/data.c
  )
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)

#queue_writer
add_executable(queue_writer "")
target_link_libraries(queue_writer PUBLIC lib)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(queue_writer 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/queue_writer/queue_writer.c
  )
install(TARGETS queue_writer DESTINATION bin)

#queue_reader
add_executable(queue_reader "")
target_link_libraries(queue_reader PUBLIC lib)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib/include)
target_sources(queue_reader 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/queue_reader/queue_reader.c
  )
install(TARGETS queue_reader DESTINATION bin)
