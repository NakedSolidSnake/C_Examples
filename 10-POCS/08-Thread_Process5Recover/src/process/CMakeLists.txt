add_definitions(-DPROCESS)


add_library(mem "")
target_link_libraries(mem PUBLIC ipc)
target_sources(mem
PUBLIC 
${CMAKE_SOURCE_DIR}/src/libs/system_memory.c
)
target_include_directories(mem 
PUBLIC 
${CMAKE_SOURCE_DIR}/libs
)

add_library(aux "")
# target_link_libraries(mem PUBLIC ipc)
target_sources(aux
PUBLIC 
${CMAKE_SOURCE_DIR}/src/libs/aux.c
)
target_include_directories(aux 
PUBLIC 
${CMAKE_SOURCE_DIR}/libs
)  

add_executable(program_a "")
target_link_libraries(program_a PUBLIC mem)
target_sources(program_a
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_a.c
)
target_include_directories(program_a 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
${CMAKE_SOURCE_DIR}/src/libs
)

add_executable(program_b "")
target_link_libraries(program_b PUBLIC mem)
target_sources(program_b
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_b.c
)
target_include_directories(program_b 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
${CMAKE_SOURCE_DIR}/src/libs
)

add_executable(program_monitor "")
target_link_libraries(program_monitor PUBLIC mem)
target_sources(program_monitor
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/monitor.c
)
target_include_directories(program_monitor 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
${CMAKE_SOURCE_DIR}/src/libs
)


add_executable(process "")
target_link_libraries(process PUBLIC mem)
target_sources(process
PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(process 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
${CMAKE_SOURCE_DIR}/src/libs
)