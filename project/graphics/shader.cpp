/** ############################################################################
 *  \file   shader.cpp
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include <fstream>
#include <iostream>
#include <sstream>

#include "shader.h"

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
        std::cerr << "ERROR::SHADER: Compile time error" << infoLog << std::endl;
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
    std::string vertexFile,
    std::string fragmentFile
)
{
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit);
    fShaderFile.exceptions(std::ifstream::failbit);
    vShaderFile.open(vertexFile);
    fShaderFile.open(fragmentFile);

    std::string vertexCode;
    std::string fragmentCode;

    try
    {
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vertexCode  = vShaderStream.str();
        fragmentCode= fShaderStream.str();
    }
    catch(std::ifstream::failure &ex)
    {
        std::cerr << "SHADER::PROGRAM: Failed to open file" << std::endl;
        vShaderFile.close();
        fShaderFile.close();
        return;
    }

    vShaderFile.close();
    fShaderFile.close();

    GLuint  vertex, fragment;

    if (!createShader(vertexCode, GL_VERTEX_SHADER, vertex))
    {
        return;
    }
    if (!createShader(fragmentCode, GL_FRAGMENT_SHADER, fragment))
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
        std::cerr << "SHADER::PROGRAM: linking failed" << std::endl;
        std::cerr << infoLog << std::endl;

        glDeleteProgram(id);
    }
    else
    {
        compiled = true;
        dbgprint1("\n shader %d is compiled", id);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
