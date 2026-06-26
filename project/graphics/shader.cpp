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
 * @brief createShader
 * @param source
 * @param type
 * @return
 ******************************************************************************/
static GLuint	createShader(
	std::string_view	source,
	GLenum				type
)
{
	GLuint		id		= glCreateShader(type);
	const char*	code	= source.data();
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
 * @param vertexCode
 * @param fragmentCode
 ******************************************************************************/
Shader::Shader(
	std::string_view vertexCode,
	std::string_view fragmentCode
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

/**
 * @brief Shader::create
 * @param vertexCode
 * @param fragmentCode
 * @return
 ******************************************************************************/
Shader::Ptr Shader::create(
	std::string_view vertexCode,
	std::string_view fragmentCode
)
{
	return Shader::Ptr(new Shader{vertexCode, fragmentCode});
}

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
void	Shader::use( void) const noexcept
{
	glUseProgram(id);
}
