/** ############################################################################
 *  \file   manager.cpp
 *  \author p@nsk
 *  \date   25.06.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include "manager.h"
#include <graphics/shader.h>
#include <graphics/texture.h>

#include <sstream>
#include <fstream>
#include <iostream>

/**
 * @brief Manager::Manager
 * @param path
 ******************************************************************************/
Manager::Manager(
	const std::string& path
)
{
	size_t found = path.find_last_of("/\\");
	resPath = path.substr(0, found);
	dbgprint1("  Manager::resPath: %s\n", resPath.c_str());
}

/**
 * @brief Manager::getFileContent
 * @param path
 * @return
 ******************************************************************************/
std::string Manager::getFileContent(
	std::string_view path
) const
{
	std::fstream file;
	file.open(resPath + "/" + path.data(), std::ios::in | std::ios::binary);
	if (!file.is_open())
		throw std::runtime_error("Failed to open file: " + std::string(path));

	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

/**
 * @brief Manager::loadShader
 * @param shaderName
 * @param vertexPath
 * @param fragmentPath
 * @return
 ******************************************************************************/
Render::Shader::Ptr Manager::loadShader (
	const std::string& shaderName,
	std::string_view vertexPath,
	std::string_view fragmentPath
)
{
	std::string vertexCode = getFileContent(vertexPath);
	std::string fragmentCode = getFileContent(fragmentPath);

	MShader[shaderName] = Render::Shader::create(vertexCode, fragmentCode);

	return MShader[shaderName];
}

/**
 * @brief Manager::getShader
 * @param shaderName
 * @return
 ******************************************************************************/
Render::Shader::Ptr Manager::getShader(
	const std::string& shaderName
) const
{
	mapShader::const_iterator it = MShader.find(shaderName);
	if (it != MShader.end())
		throw std::runtime_error("Cant find the shader: " + shaderName);

	return it->second;
}

/**
 * @brief Manager::loadTexture
 * @param textureName
 * @param texturePath
 * @return
 ******************************************************************************/
Render::Texture::Ptr Manager::loadTexture (
	const std::string& textureName,
	std::string_view texturePath
)
{
	MTexture[textureName] = Render::Texture::create(texturePath);

	return MTexture[textureName];
}

/**
 * @brief Manager::getTexture
 * @param textureName
 * @return
 ******************************************************************************/
Render::Texture::Ptr Manager::getTexture(
	const std::string& textureName
) const
{
	mapTexture::const_iterator it = MTexture.find(textureName);
	if (it == MTexture.end())
		throw std::runtime_error("Cant find the texture: " + textureName);

	return it->second;
}
