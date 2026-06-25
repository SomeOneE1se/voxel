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
#include <constants.h>

#include <graphics/shader.h>
#include <graphics/texture.h>
#include <window/window.h>
#include <window/events.h>
#include <manager/manager.h>

#include <iostream>
#include <bitset>

/*
 ---------------------------------------------------------------------------- */

/**
 * @brief main
 * @return
 ******************************************************************************/
int main(int argc, char** argv)
{
    dbgprint0("  Start with debug\n");
    TUInt8 modulesErr = 0;

    modulesErr |= Window::initialize(WIN_WIDTH, WIN_HEIGHT, "Window");
    modulesErr |= Events::initialize() << 1;

    if (modulesErr)
    {
        std::cerr << "! Program Start Error - "
                  << std::bitset<8>(modulesErr) << std::endl;
    }
    else
    {
        Manager manager(argv[0]);
        auto pShader = manager.loadShader(  "DefaultShader",
                                            "shaders/vertex.glsl",
                                            "shaders/fragment.glsl");
        if (!pShader)
        {
            std::cerr << "! Cant create shader: " << "DefaultSahder" << std::endl;
            return -1;
        }

        auto pTexture = manager.loadTexture("Flowers", "textures/texture1.png");
        if (!pTexture)
        {
            std::cerr << "! Cant load texture: " << "Flowers" << std::endl;
            return -1;
        }

        GLuint VAO  = 0;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        GLuint VBO = 0;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), nullptr);

        glClearColor(0.7f, 0.8f, 0.7f, 1);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
                glClearColor(0.7f, 0.7f, 0.9f, 1);

            glClear(GL_COLOR_BUFFER_BIT);

            pShader->use();
            pTexture->bind();
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            glBindVertexArray(0);

            Window::swapBuffers();
        }
        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
    }

    Window::terminate();
    return 0;
}
