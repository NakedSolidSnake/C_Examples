cmake_minimum_required(VERSION 3.7.0)

project(Resgitry)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


function(compile PATH)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PATH})
    file(GLOB FILES ${PROJECT_SOURCE_DIR}/${PATH}/*.c)
    set(FILE_LIST ${FILES})

    foreach(ARG ${FILE_LIST})
        get_filename_component(filename "${ARG}" NAME)    
        get_filename_component(filename_noext "${filename}" NAME_WE)
    
        add_executable(${filename_noext} "")
        target_link_libraries(${filename_noext} PUBLIC m)
        target_sources(${filename_noext}
        PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/${PATH}/${filename}
        )
        target_include_directories(${filename_noext}
         PUBLIC 
         ${CMAKE_CURRENT_LIST_DIR}/include
         /usr/include
         )
        install(DIRECTORY filename_noext DESTINATION ${PATH}) 
    endforeach()
endfunction()

# compile("list01_variaveis_e_expressoes")
# compile("list02_comandos_condicionais")
# compile("list03_comandos_de_repeticao")
# compile("list04_vetores_e_matrizes")
# compile("list05_strings")
# compile("list06_structs")
# compile("list07_funcoes")
# compile("list08_recursao")
# compile("list09_ponteiros")
# compile("list10_alocacao_dinamica")
compile("list11_arquivos")