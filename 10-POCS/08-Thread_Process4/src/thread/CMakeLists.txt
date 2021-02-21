add_definitions(-DTHREAD)

add_library(program_a "")
target_sources(program_a
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_a.c
)
target_include_directories(program_a 
PUBLIC 
${CMAKE_SOURCE_DIR}/tasks
)  

add_library(program_b "")
target_sources(program_b
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_b.c
)
target_include_directories(program_b 
PUBLIC 
${CMAKE_SOURCE_DIR}/tasks
)  

add_executable(thread "")
target_link_libraries(thread PUBLIC program_a program_b pthread)
target_sources(thread
PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(thread 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)


