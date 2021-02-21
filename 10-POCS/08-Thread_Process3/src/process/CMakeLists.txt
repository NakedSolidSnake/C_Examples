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

add_executable(task "")
target_sources(task
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/tasks.c
)
target_include_directories(task 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)
