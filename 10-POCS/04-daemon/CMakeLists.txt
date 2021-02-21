cmake_minimum_required(VERSION 3.7.0)

project(server)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX "/home/$ENV{USER}")
set(CMAKE_BUILD_TYPE Debug)

macro(install_symlink filepath sympath)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${filepath} ${sympath})")
    install(CODE "message(\"-- Created symlink: ${sympath} -> ${filepath}\")")
endmacro(install_symlink)

add_executable(server "")
target_link_libraries(server PUBLIC comm)
target_sources(server
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
  )

# Create package
set(CPACK_PACKAGE_DESCRIPTION "server package")
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_PACKAGE_VENDOR "Solid Company")
set(CPACK_PACKAGE_CONTACT "support@acme.corp")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/toupper)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
include (CPack)

install(TARGETS server DESTINATION bin)
install(FILES daemon.service DESTINATION dat)
install_symlink(${CMAKE_INSTALL_PREFIX}/toupper/dat/daemon.service /etc/systemd/system/daemon.service)
