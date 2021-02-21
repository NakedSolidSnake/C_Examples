cmake_minimum_required(VERSION 3.7.0)

project(launcher)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX "/home/$ENV{USER}")
set(CMAKE_BUILD_TYPE Debug)

set(CPACK_DEBIAN_PACKAGE_CONTROL_STRICT_PERMISSION TRUE)


# macro(install_symlink filepath sympath)
#     install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${filepath} ${sympath})")
#     install(CODE "message(\"-- Created symlink: ${sympath} -> ${filepath}\")")
# endmacro(install_symlink)

add_executable(launch "")
# target_link_libraries(launch PUBLIC comm)
target_sources(launch
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/launch.c
  )

add_executable(process "")
# target_link_libraries(launch PUBLIC comm)
target_sources(process
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/process.c
  )

# Create package
set(CPACK_PACKAGE_DESCRIPTION "launcher package")
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_PACKAGE_VENDOR "Solid Company")
set(CPACK_PACKAGE_CONTACT "support@acme.corp")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/launcher)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

#call script to create a symbolic link
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/postinst")
# set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/postrm")
include (CPack)

install(TARGETS launch DESTINATION bin)
install(TARGETS process DESTINATION bin)
install(FILES launcher.service PERMISSIONS OWNER_WRITE OWNER_READ DESTINATION dat)
# install(FILES postinstall.sh PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ DESTINATION dat)
# install_symlink(${CMAKE_INSTALL_PREFIX}/launcher/dat/launcher.service /etc/systemd/system/launcher.service)
