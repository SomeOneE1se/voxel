#ifndef TEXTURE_H
#define TEXTURE_H

#include <project.h>
#include <string>

class Texture
{
public:
    TUInt32 id;
    Texture(TUInt32 id);
    ~Texture();

    void bind();
};

//extern Texture *load_texture(std::string fileName);

#endif // TEXTURE_H
