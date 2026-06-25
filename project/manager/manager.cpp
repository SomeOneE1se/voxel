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
	std::string path
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
	std::string path
	) const
{
	std::fstream file;
	file.open(resPath + "/" + path.c_str(), std::ios::in | std::ios::binary);
	if (!file.is_open())
		throw std::runtime_error("Failed to open file: " + path);

	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

/**
 * @brief Manager::loadShader
 * @param shaderName
 * @param vertex
 * @param fragment
 * @return
 ******************************************************************************/
Render::Shader::Ptr Manager::loadShader (
	std::string shaderName,
	std::string vertexPath,
	std::string fragmentPath
	)
{
	std::string vertexCode = getFileContent(vertexPath);
	std::string fragmentCode = getFileContent(fragmentPath);

	MShader[shaderName] = std::make_shared<Render::Shader>(vertexCode, fragmentCode);
	Render::Shader::Ptr newShader = MShader[shaderName];

	return newShader;
}

/**
 * @brief Manager::getShader
 * @param shaderName
 * @return
 ******************************************************************************/
Render::Shader::Ptr Manager::getShader(
	std::string shaderName
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
 * @param texture
 * @return
 ******************************************************************************/
Render::Texture::Ptr Manager::loadTexture (
	std::string textureName,
	std::string texturePath
	)
{
	MTexture[textureName] = std::make_shared<Render::Texture>(texturePath);
	Render::Texture::Ptr newTexture = MTexture[textureName];

	return newTexture;
}

/**
 * @brief Manager::getTexture
 * @param textureName
 * @return
 ******************************************************************************/
Render::Texture::Ptr Manager::getTexture(
	std::string textureName
	) const
{
	mapTexture::const_iterator it = MTexture.find(textureName);
	if (it == MTexture.end())
		throw std::runtime_error("Cant find the texture: " + textureName);

	return it->second;
}
