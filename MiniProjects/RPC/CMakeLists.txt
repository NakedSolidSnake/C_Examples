cmake_minimum_required(VERSION 3.2)

project(WebServer)

set (CMAKE_C_FLAGS "-Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)


# Build database library
add_library(database "")

target_link_libraries( database PUBLIC mysqlclient)

target_sources(database 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/database.c
  )

target_include_directories( database 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    /usr/include/mysql
  )

#   teste insert
add_executable(insert "")
target_link_libraries(insert PUBLIC database)

target_sources(insert 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/tests/insert.c
  )

target_include_directories(insert 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )

  #   teste select
add_executable(select "")
target_link_libraries(select PUBLIC database)

target_sources(select 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/tests/select.c
  )

target_include_directories(select 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )

# menu
add_executable(menu "")
target_link_libraries(menu PUBLIC database)

target_sources(menu 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/menu.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_common.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_insert.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_delete.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_lists.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_quit.c
    ${CMAKE_CURRENT_LIST_DIR}/src/submenu_update.c
  )

target_include_directories(menu 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
  )