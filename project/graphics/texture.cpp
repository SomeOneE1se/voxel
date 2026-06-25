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
#include <iostream>

using namespace Render;

/**
 * @brief Texture::Texture
 * @param filename
 ******************************************************************************/
Texture::Texture(std::string filename)
{
    loaded  = 0;
    width   = 0;
    height  = 0;
    load_texture(filename);
}

/**
 * @brief Texture::~Texture
 ******************************************************************************/
Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

/**
 * @brief Texture::bind
 ******************************************************************************/
void    Texture::bind( void) const
{
    glBindTexture(GL_TEXTURE_2D, id);
}

/**
 * @brief Texture::isLoaded
 * @return
 ******************************************************************************/
TBool   Texture::isLoaded( void) const
{
    return loaded;
}

/**
 * @brief Texture::load_texture
 * @param filename
 * @return
 ******************************************************************************/
int Texture::load_texture(std::string filename){
    id = png_load(filename.c_str(), &width, &height);
    if (id == 0)
    {
        std::cerr << "! Could not load texture " << filename << std::endl;
        return 1;
    }
    dbgprint1("  Texture %d is loaded\n", id);
    loaded = 1;
    return 0;
}
