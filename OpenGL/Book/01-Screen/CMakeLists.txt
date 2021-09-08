cmake_minimum_required(VERSION 3.09)

project(Window)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_FLAGS "-std=c99 -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(window main.c)
target_link_libraries(window  GLEW glfw3 GL X11 pthread Xrandr Xi dl m glad)
