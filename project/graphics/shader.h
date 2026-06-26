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
#include <string_view>

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
	Shader( std::string_view vertexCode, std::string_view fragmentCode);

public:
	using Ptr	= TShared<Shader>;

	Shader( void)			= delete;
	Shader( const Shader&)	= delete;
	Shader( Shader&&)		= delete;
	~Shader( void);

	Shader& operator=( const Shader&)	= delete;
	Shader& operator=( Shader&&)		= delete;

	static Shader::Ptr create(
		std::string_view vertexCode,
		std::string_view fragmentCode
	);

	void	use( void) const noexcept;
};

}; // namespace Render
#endif // SHADER_H
