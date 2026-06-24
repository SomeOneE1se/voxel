/** ############################################################################
 *  \file   window.h
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include <iostream>
#include <glad/glad.h>
#include "window.h"

/*
 ---------------------------------------------------------------------------- */

GLFWwindow *Window::pWindow = nullptr;

/*
 ---------------------------------------------------------------------------- */

/**
 * @brief Window::initialize
 * @param width
 * @param height
 * @param title
 * @return
 ******************************************************************************/
TInt Window::initialize(
    TInt width,
    TInt height,
    const TChar *title
)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,  GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    pWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (pWindow == nullptr)
    {
        std::cerr << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cerr << "Failed to load GLAD " << std::endl;
        return -1;
    }

    glViewport(0,0, width,height);
    return 0;
}

/**
 * @brief Window::get_Window
 * @return
 ******************************************************************************/
GLFWwindow * Window::getWindow( void)
{
    return pWindow;
}

/**
 * @brief Window::isShouldClose
 * @return
 ******************************************************************************/
TBool Window::isShouldClose( void)
{
    return glfwWindowShouldClose(pWindow);
}

/**
 * @brief Window::setShouldClose
 * @param flag
 ******************************************************************************/
void Window::setShouldClose(
    TBool   flag
)
{
    glfwSetWindowShouldClose(pWindow, flag);
}

/**
 * @brief Window::swapBuffers
 ******************************************************************************/
void Window::swapBuffers( void)
{
    glfwSwapBuffers(pWindow);
}

/**
 * @brief Window::terminate
 ******************************************************************************/
void Window::terminate( void)
{
    pWindow = nullptr;
    return glfwTerminate();
}
