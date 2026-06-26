/** ############################################################################
 *  \file   texture.cpp
 *  \author p@nsk
 *  \date   24.06.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include "texture.h"
#include <glad/glad.h>
#include <manager/manager.h>
#include <stdexcept>

using namespace Render;

/**
 * @brief Texture::load_texture
 * @param filename
 * @return
 ******************************************************************************/
static TUInt32 load_texture(
	std::string filename,
	TInt& width,
	TInt& height
)
{
	TUInt32 id = png_load(filename.c_str(), &width, &height);
	if (id == 0U)
	{
		throw std::runtime_error("! Could not load texture " + filename);
	}

	dbgprint1("  Texture %d is loaded\n", id);

	return id;
}

/**
 * @brief Texture::Texture
 * @param filename
 ******************************************************************************/
Texture::Texture(
	std::string filename
	) : width(0), height(0), id(load_texture(filename, width, height))
{ }

/**
 * @brief Texture::~Texture
 ******************************************************************************/
Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

/**
 * @brief Texture::create
 * @param filename
 * @return
 ******************************************************************************/
Texture::Ptr Texture::create( std::string filename)
{
	return Texture::Ptr(new Texture{filename});
}

/**
 * @brief Texture::bind
 ******************************************************************************/
void	Texture::bind( void) const noexcept
{
	glBindTexture(GL_TEXTURE_2D, id);
}
