#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

const char *main_template = 
{
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "#include <string.h>\n\n"
    "int main(int argc, char *argv[])\n"
    "{\n\n"
    "    return EXIT_SUCCESS;\n"
    "}\n"    
};

const char *cmake_template = 
{
    "cmake_minimum_required(VERSION 3.7.0)\n"
    "project(%s)\n\n"
    "set (CMAKE_C_FLAGS \"-D_GNU_SOURCE -Wall -std=c99\")\n"
    "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)\n"
    "set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)\n"
    "set(CMAKE_BUILD_TYPE Debug)\n\n"

    "# build %s\n"
    "add_executable(%s \"\")\n"
    "# target_link_libraries(%s PUBLIC mylib)\n\n"

    "target_sources(%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/src/main.c\n"
    ")\n\n"

    "install(TARGETS %s DESTINATION bin)\n"
};

bool create_main_template(void);
bool create_cmake_template(const char *project_name, const char *binary_name);

int main(int argc, char *argv[])
{    
    if(argc != 4)
    {
        fprintf(stdout, "Cannot create project.\nUsage.: %s <path> <project name> <binary name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = argv[1];
    char *project_name = argv[2];
    char *binary_name = argv[3];
    
    int ret = mkdir(path, 0666);
    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    ret = chdir(path);

    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    ret = mkdir("build", 0666);
    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    ret = mkdir("src", 0666);
    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    ret = mkdir("include", 0666);
    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    if(create_cmake_template(project_name, binary_name) == false)
        return EXIT_FAILURE;

    // FILE *cmake_fd = fopen("CMakeLists.txt", "w");
    // if(cmake_fd == NULL)
    //     return EXIT_FAILURE;

    // fprintf(cmake_fd, cmake_template, project_name, binary_name, binary_name, binary_name, binary_name, binary_name, binary_name);
    // fclose(cmake_fd);

    ret = chdir("src");
    if(ret != 0)
    {
        return EXIT_FAILURE;
    }

    // FILE *main_fd = fopen("main.c", "w");
    // if(main_fd == NULL)
    //     return EXIT_FAILURE;

    // fwrite(main_template, 1, strlen(main_template), main_fd);
    // fclose(main_fd);

    if(create_main_template() == false)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

bool create_main_template(void)
{    
    FILE *main_fd = fopen("main.c", "w");
    if(main_fd == NULL)
        return false;

    fwrite(main_template, 1, strlen(main_template), main_fd);
    fclose(main_fd);
    return true;
}

bool create_cmake_template(const char *project_name, const char *binary_name)
{
    FILE *cmake_fd = fopen("CMakeLists.txt", "w");
    if(cmake_fd == NULL)
        return EXIT_FAILURE;

    fprintf(cmake_fd, cmake_template, project_name, binary_name, binary_name, binary_name, binary_name, binary_name, binary_name);
    fclose(cmake_fd);
}