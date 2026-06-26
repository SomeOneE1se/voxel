/** ############################################################################
 *  \file   manager.h
 *  \author p@nsk
 *  \date   25.06.2026
 *  \brief
 * _____________________________________________________________________________
 */
#ifndef MANAGER_H
#define MANAGER_H

#include <project.h>
#include <string>
#include "uni_base_types.h"
#include "graphics/shader.h"
#include "graphics/texture.h"

using mapShader		= TMap<std::string, Render::Shader::Ptr>;
using mapTexture	= TMap<std::string, Render::Texture::Ptr>;

/**
 * @brief The Manager class
 ******************************************************************************/
class Manager
{
	std::string resPath;
	mapShader   MShader;
	mapTexture  MTexture;

	std::string getFileContent( std::string_view path) const;

public:
	Manager( const std::string& path);
	Manager( const Manager&)			= delete;
	Manager( Manager&&)					= delete;
	Manager& operator=( const Manager&)	= delete;
	Manager& operator=( Manager&&)		= delete;

	Render::Shader::Ptr loadShader(
		const std::string& shaderName,
		std::string_view vertexPath,
		std::string_view fragmentPath
	);
	Render::Shader::Ptr getShader(const std::string&  shaderName) const;

	Render::Texture::Ptr loadTexture(
		const std::string&  textureName,
		std::string_view texturePath
	);

	Render::Texture::Ptr getTexture(const std::string&  textureName) const;
};

int png_load(const char *file, int *width, int *height);

#endif // MANAGER_H
