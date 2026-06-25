/** ############################################################################
 *  \file   shader.cpp
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include <stdexcept>
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
 * @brief Shader::createShader
 * @param source
 * @param type
 * @param id
 * @return
 ******************************************************************************/
static GLuint	createShader(
	std::string	source,
	GLenum		type
	)
{
    id = glCreateShader(type);
    const char* code = source.c_str();
    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);

	GLint	success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar	infoLog[1024];
		glGetShaderInfoLog(id, 1024, nullptr, infoLog);
		throw std::runtime_error("ERROR::SHADER: Compile time error: " + std::string(infoLog));
	}

	return id;
}

/**
 * @brief Shader::Shader
 * @param vertexPath
 * @param fragmentPath
 ******************************************************************************/
Shader::Shader(
	std::string vertexCode,
	std::string fragmentCode
	)
{
	GLuint vertex	= createShader(vertexCode, GL_VERTEX_SHADER);
	GLuint fragment	= createShader(fragmentCode, GL_FRAGMENT_SHADER);

	id = glCreateProgram();
	glAttachShader(id, vertex);
	glAttachShader(id, fragment);
	glLinkProgram(id);

	GLint	success;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar	infoLog[512];
		glGetProgramInfoLog(id, 512, nullptr, infoLog);

		glDeleteProgram(id);

		throw std::runtime_error("SHADER::PROGRAM: linking failed" + std::string(infoLog));
	}

	dbgprint1("  Shader %d is compiled\n", id);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
