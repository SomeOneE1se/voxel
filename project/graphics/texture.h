/** ############################################################################
 *  \file   texture.h
 *  \author p@nsk
 *  \date   24.06.2026
 *  \brief
 * _____________________________________________________________________________
 */
#ifndef TEXTURE_H
#define TEXTURE_H

#include <project.h>
#include <string>

namespace Render{

/**
 * @brief The Texture class
 ******************************************************************************/
class Texture
{
    TUInt32 id;
    TInt    width;
    TInt    height;
    TBool   loaded;

public:
    Texture(std::string filename);
   ~Texture();

    Texture()   = delete;
    Texture(Texture&)   = delete;
    Texture& operator=(const Texture&)  = delete;

    void    bind    ( void) const;
    TBool   isLoaded( void) const;

    int     load_texture(std::string filename);
};

}; // namespace Render
#endif // TEXTURE_H
