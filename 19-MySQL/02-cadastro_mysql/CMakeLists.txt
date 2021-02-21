cmake_minimum_required(VERSION 3.2)

project(database)


set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)


add_library(database "")

target_link_libraries( database PUBLIC mysqlclient)

target_sources(database 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/db.c
  )

target_include_directories( database 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    /usr/include/mysql
  )


add_executable(app "")
target_link_libraries(app PUBLIC database)

target_sources(app 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/main.c
  )

target_include_directories(app 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )
