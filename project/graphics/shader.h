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

#include "uni_base_types.h"

namespace Render {
/**
 * @brief The Shader class
 ******************************************************************************/
class Shader
{
private:
	TUInt32 id;

public:
	using Ptr	= TShared<Shader>;

	Shader( std::string vertexCode, std::string fragmentCode);
	Shader( void)			= delete;
	Shader( const Shader&)	= delete;
	Shader( Shader&&)		= delete;
	~Shader( void);

	Shader& operator=( const Shader&)	= delete;
	Shader& operator=( Shader&&)		= delete;

	void	use( void)	const;
};

}; // namespace Render
#endif // SHADER_H
