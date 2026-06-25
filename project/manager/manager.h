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
#include <map>
#include "graphics/shader.h"
#include "graphics/texture.h"

using mapShader		= std::map<std::string, Render::Shader::Ptr>;
using mapTexture	= std::map<std::string, Render::Texture::Ptr>;

/**
 * @brief The Manager class
 ******************************************************************************/
class Manager
{
    std::string resPath;

	mapShader   MShader;
	mapTexture  MTexture;

	std::string getFileContent( std::string path) const;

public:
    Manager(const std::string& path);
   ~Manager() = default;

    Manager(const Manager& ) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager& operator=(Manager&&) = delete;
    Manager(Manager&&) = delete;


    std::shared_ptr<Render::Shader> getShader(const std::string shaderName) const;


    std::shared_ptr<Render::Texture> getTexture(const std::string textureName) const;
	Render::Shader::Ptr loadShader(
		std::string shaderName,
		std::string vertexPath,
		std::string fragmentPath
	);
	Render::Texture::Ptr loadTexture(
		std::string shaderName,
		std::string texturePath
	);
};

int png_load(const char *file, int *width, int *height);

#endif // MANAGER_H
