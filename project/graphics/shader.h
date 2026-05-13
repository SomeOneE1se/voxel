#ifndef SHADER_H
#define SHADER_H

#include <project.h>
#include <string>

class Shader
{
public:
    TUInt32 id;
    Shader( TUInt32 id);
    ~Shader( void);

    void use( void);
};

extern Shader *load_shader(std::string vertexFile, std::string fragmentFile);

#endif // SHADER_H
