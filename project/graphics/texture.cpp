#include "texture.h"
#include "glad/glad.h"

/**
*******************************************************************************/
Texture::Texture(TUInt32 id) : id(id)
    {}

/**
*******************************************************************************/
Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

/**
*******************************************************************************/
void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}
