add_definitions(-DTHREAD)

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


add_library(program_a "")
target_link_libraries(program_a PUBLIC mem)
target_sources(program_a
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_a.c
)
target_include_directories(program_a 
PUBLIC 
${CMAKE_SOURCE_DIR}/tasks
${CMAKE_SOURCE_DIR}/src/libs
)  

add_library(program_b "")
target_link_libraries(program_b PUBLIC mem)
target_sources(program_b
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_b.c
)
target_include_directories(program_b 
PUBLIC 
${CMAKE_SOURCE_DIR}/tasks
${CMAKE_SOURCE_DIR}/src/libs
)  

add_executable(thread "")
target_link_libraries(thread PUBLIC program_a program_b mem pthread)
target_sources(thread
PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(thread 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)


