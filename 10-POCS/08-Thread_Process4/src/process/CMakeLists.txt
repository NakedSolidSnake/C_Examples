add_definitions(-DPROCESS)

add_executable(process "")
target_sources(process
PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(process 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)

add_executable(program_a "")
target_sources(program_a
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_a.c
)
target_include_directories(program_a 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)

add_executable(program_b "")
target_sources(program_b
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/program_b.c
)
target_include_directories(program_b 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)
