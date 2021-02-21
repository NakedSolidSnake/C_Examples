add_definitions(-DTHREAD)

add_library(task "")
target_sources(task
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks/tasks.c
)
target_include_directories(task 
PUBLIC 
${CMAKE_SOURCE_DIR}/tasks
)  

add_executable(thread "")
target_link_libraries(thread PUBLIC task pthread)
target_sources(thread
PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories(thread 
PUBLIC 
${CMAKE_SOURCE_DIR}/src/tasks
)


