#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum 
{
    Error_No_Error = 0,
    Error_Create_Window = 1,
    Error_Glad_Initialize
} Error;

typedef struct 
{
    Error id;
    const char *message;
} Error_Map;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

void print_error(int status, void *args)
{
    Error_Map *error_map = (Error_Map *)args;
    puts(error_map[status].message); 
    glfwTerminate(); 
}

int main()
{
    const Error_Map error_map[] = 
    {
        {.id = Error_No_Error, "Success"},
        {.id = Error_Create_Window, "Failed to create GLFW window"},
        {.id = Error_Glad_Initialize, "Failed to initialize GLAD"},
    };


    on_exit(print_error, &error_map);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if(!window)
        exit(Error_Create_Window);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        exit(Error_Glad_Initialize);

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        //render
        glClearColor(0.2F, 0.3F, 0.3F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    exit(Error_No_Error);
}

/* Handle ajust screen when an event resize is called */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}