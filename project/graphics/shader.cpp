/** ############################################################################
 *  \file   shader.cpp
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */

#include <iostream>

#include "shader.h"
using namespace Render;

/**
 * @brief Shader::~Shader
 ******************************************************************************/
Shader::~Shader( void)
{
    glDeleteProgram(id);
}

/**
 * @brief Shader::use
 ******************************************************************************/
void    Shader::use( void)  const
{
    glUseProgram(id);
}

/**
 * @brief Shader::isCompiled
 * @return
 ******************************************************************************/
TBool   Shader::isCompiled( void)   const
{
    return compiled;
}

/**
 * @brief Shader::createShader
 * @param source
 * @param type
 * @param id
 * @return
 ******************************************************************************/
bool Shader::createShader(
    const std::string& source,
    const GLenum type,
    GLuint &id
)
{
    id = glCreateShader(type);
    const char* code = source.c_str();
    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);

    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[1024];
        glGetShaderInfoLog(id, 1024, nullptr, infoLog);
        std::cerr << "! ERROR::SHADER: Compile time error" << infoLog << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Shader::Shader
 * @param vertexFile
 * @param fragmentFile
 ******************************************************************************/
Shader::Shader(
    const std::string vertexString,
    const std::string fragmentString
)
{
    GLuint  vertex, fragment;

    if (!createShader(vertexString, GL_VERTEX_SHADER, vertex))
    {
        return;
    }
    if (!createShader(fragmentString, GL_FRAGMENT_SHADER, fragment))
    {
        return;
    }

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    GLint   success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLchar  infoLog[512];
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "! SHADER::PROGRAM: linking failed" << std::endl;
        std::cerr << infoLog << std::endl;

        glDeleteProgram(id);
    }
    else
    {
        compiled = true;
        dbgprint1("  Shader %d is compiled\n", id);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
