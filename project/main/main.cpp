/** ############################################################################
 *  \file   main.cpp
 *  \author p@nsk
 *  \date   09.05.2026
 *  \brief  Main Project source file.
 * _____________________________________________________________________________
 */
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <project.h>
#include <graphics/shader.h>
#include <window/window.h>
#include <window/events.h>

#include <iostream>

/*
 ---------------------------------------------------------------------------- */
int WIDTH   = 1280;
int HEIGHT  = 720;

TFloat  vertices[]  = {
//  X       Y       Z
    0.0f,   0.5f,   0.0f,
    0.5f,  -0.5f,   0.0f,
   -0.5f,  -0.5f,   0.0f,
};

TFloat  colors[]    = {
//  R       G       B
    1.0f,   0.0f,   0.0f,
    0.0f,   1.0f,   0.0f,
    0.0f,   0.0f,   1.0f,
};

/*
 ---------------------------------------------------------------------------- */

/**
 * @brief main
 * @return
 ******************************************************************************/
int main()
{
    Window::initialize(WIDTH, HEIGHT, "Window");
    Events::initialize();

    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");
    if (!shader.isCompiled())
    {
        std::cerr << "Failed to load shader" << std::endl;
        Window::terminate();
        return 1;
    }

    GLuint VAO  = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint pVBO = 0;
    glGenBuffers(1, &pVBO);
    glBindBuffer(GL_ARRAY_BUFFER, pVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint cVBO = 0;
    glGenBuffers(1, &cVBO);
    glBindBuffer(GL_ARRAY_BUFFER, cVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, pVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, cVBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glClearColor(0.7f, 0.8f, 0.7f, 1);

    while (!Window::isShouldClose())
    {
        Events::pullEvents();

        if (Events::isJPressed(GLFW_KEY_ESCAPE))
        {
            Window::setShouldClose(true);
        }
        if (Events::isClicked(GLFW_MOUSE_BUTTON_LEFT))
            glClearColor(0.4f, 0.5f, 0.4f, 1);
        else
            glClearColor(0.7f, 0.8f, 0.7f, 1);

        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        Window::swapBuffers();
    }
    Window::terminate();
    return 0;
}
