cmake_minimum_required(VERSION 3.9.1)
set(PROJECT_NAME  core)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("{PROJECT_BINARY_DIR}/Core/")

#set (HEADER_FILES
#  ${PROJECT_SOURCE_DIR}/Common/*.h
#  ${PROJECT_SOURCE_DIR}/Framework/Device_IOCTL/*.h
#  ${PROJECT_SOURCE_DIR}/Framework/Fileoperation/*.h
#  ${PROJECT_SOURCE_DIR}/Framework/HW_Descriptor/*.h
#  ${PROJECT_SOURCE_DIR}/Framework/IDriver/*.h
#  ${PROJECT_SOURCE_DIR}/Hardware/Device_Driver/*.h
# )

set(include_dir "${PROJECT_SOURCE_DIR}/Core/")
file(GLOB_RECURSE include_dir "${include_dir}/*.h")

set(src_dir "${PROJECT_SOURCE_DIR}/Core/")
file(GLOB_RECURSE src_dir "${src_dir}/*.c")

add_executable(${PROJECT_NAME} ${src_dir} ${HEADER_FILES})
