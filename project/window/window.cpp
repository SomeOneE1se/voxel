#include <iostream>
#include "window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


GLFWwindow *Window::window;

/**
*******************************************************************************/
TInt Window::initialize(
        TInt width,
        TInt height,
        const TChar *title
){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,  GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glViewport(0,0, width,height);
    return 0;
}

/**
*******************************************************************************/
TBool Window::isShouldClose( void)
{
    return glfwWindowShouldClose(window);
}

/**
*******************************************************************************/
void Window::setShouldClose(
        TBool flag
){
    glfwSetWindowShouldClose(window, flag);
}

/**
*******************************************************************************/
void Window::swapBuffers( void)
{
    glfwSwapBuffers(window);
}

/**
*******************************************************************************/
void Window::terminate( void)
{
    return glfwTerminate();
}
