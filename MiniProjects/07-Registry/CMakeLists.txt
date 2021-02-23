cmake_minimum_required(VERSION 3.7.0)

project(Resgitry)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

function(add_test_unit BIN_NAME BIN SOURCE)
  add_executable(${BIN} ${SOURCE})
  set_target_properties(${BIN}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests
    )
    add_test(NAME ${BIN_NAME} COMMAND ${BIN})
endfunction()

enable_testing()


# library domain
add_library(domain "")
target_sources(domain 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/domain/person.c
    )
target_include_directories(domain 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include   
)

add_library(database "")
target_link_libraries(database PUBLIC mysqlclient)
target_sources(database 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/database/db.c
    )
target_include_directories(database 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include 
    /usr/include/mysql  
)

add_library(list "")
# target_link_libraries(list PUBLIC mysqlclient)
target_sources(list 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/list/list_dynamic.c
    )
target_include_directories(list 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include     
)

find_package(PkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GTK "gtk+-2.0")
  if (GTK_FOUND)
    add_library(view "")    
    target_sources(view 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/view/insertwindow.c
    ${CMAKE_CURRENT_LIST_DIR}/src/view/mainwindow.c
    )
    target_include_directories(view PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(view PUBLIC ${GTK_LIBRARIES})
    add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
  endif()
endif()

add_test_unit(create test_create testcase/test_create_destroy_person.c)
target_link_libraries(test_create PUBLIC domain)
target_include_directories(test_create PUBLIC include)

add_test_unit(change_name test_change_name testcase/test_change_name_person.c)
target_link_libraries(test_change_name PUBLIC domain)
target_include_directories(test_change_name PUBLIC include)

add_test_unit(change_address test_change_address testcase/test_change_address_person.c)
target_link_libraries(test_change_address PUBLIC domain)
target_include_directories(test_change_address PUBLIC include)

add_test_unit(change_age test_change_age testcase/test_change_age_person.c)
target_link_libraries(test_change_age PUBLIC domain)
target_include_directories(test_change_age PUBLIC include)

# add_test_unit(insert_window test_insertwindow testcase/test_insertwindow.c)
# target_link_libraries(test_insertwindow PUBLIC view)
# target_include_directories(test_insertwindow PUBLIC include)

add_test_unit(main_window test_mainwindow testcase/test_mainwindow.c)
target_link_libraries(test_mainwindow PUBLIC view)
target_include_directories(test_mainwindow PUBLIC include)

add_test_unit(database_init  database_init_test testcase/test_database_connection.c)
target_link_libraries(database_init_test PUBLIC database)
target_include_directories(database_init_test PUBLIC include)

add_test_unit(database_insert  database_insert_test testcase/test_database_insert.c)
target_link_libraries(database_insert_test PUBLIC database domain)
target_include_directories(database_insert_test PUBLIC include)

add_test_unit(database_update  database_update_test testcase/test_database_update.c)
target_link_libraries(database_update_test PUBLIC database domain)
target_include_directories(database_update_test PUBLIC include)

add_test_unit(database_deleteall  database_deleteall_test testcase/test_database_deleteall.c)
target_link_libraries(database_deleteall_test PUBLIC database domain)
target_include_directories(database_deleteall_test PUBLIC include)

add_test_unit(database_select  database_select_test testcase/test_database_select.c)
target_link_libraries(database_select_test PUBLIC database domain)
target_include_directories(database_select_test PUBLIC include)

add_test_unit(list_create  test_list_create testcase/test_list_create.c)
target_link_libraries(test_list_create PUBLIC database list)
target_include_directories(test_list_create PUBLIC include)

add_test_unit(list_insert  test_list_insert testcase/test_list_insert.c)
target_link_libraries(test_list_insert PUBLIC database list)
target_include_directories(test_list_insert PUBLIC include)

add_test_unit(list_get  test_list_get testcase/test_list_get.c)
target_link_libraries(test_list_get PUBLIC database list)
target_include_directories(test_list_get PUBLIC include)

# add_custom_command(
#         TARGET
#         Resgitry
#         POST_BUILD        
#         COMMAND 
#           /bin/sh ${CMAKE_CURRENT_LIST_DIR}/scripts/check_leaks.sh
#         COMMENT 
#           "Verify leaks"
#         VERBATIM
#         )