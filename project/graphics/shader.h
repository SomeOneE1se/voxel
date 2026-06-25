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
#include <memory>

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
	using Ptr = std::shared_ptr<Render::Shader>;

	Shader( std::string vertexCode, std::string fragmentCode);
	Shader( void) = delete;
	Shader( Shader&) = delete;
	~Shader( void);

	Shader& operator=( const Shader&) = delete;

	void	use( void)	const;
};

}; // namespace Render
#endif // SHADER_H
