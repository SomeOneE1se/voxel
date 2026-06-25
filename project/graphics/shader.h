/** ############################################################################
 *  \file   shader.h
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#ifndef SHADER_H
#define SHADER_H

#include <project.h>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Render {
/**
 * @brief The Shader class
 ******************************************************************************/
class Shader
{
private:
	TUInt32 id;

public:

    Shader( const std::string vertexString, const std::string fragmentString);
   ~Shader( void);

    Shader() = delete;
    Shader(Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void    use( void)      const;
};

}; // namespace Render
#endif // SHADER_H
