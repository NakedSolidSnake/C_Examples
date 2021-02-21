add_library(led "")

#pc 
if(${ARCH} STREQUAL "PC")
  message("pc compiling...")
  target_sources(led 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/pc/src/led.c
    )
endif()

#raspberry
if(${ARCH} STREQUAL "RASPBERRY")
  target_link_libraries(led PUBLIC wiringPi)
  target_sources(led 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/raspberry/src/led.c
    )
  message("raspberry compiling...")
endif()

target_include_directories(led 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include)
