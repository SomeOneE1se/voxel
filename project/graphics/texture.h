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
#include <memory>

namespace Render {

/**
 * @brief The Texture class
 ******************************************************************************/
class Texture
{
	TInt	width;
	TInt	height;
	TUInt32	id;

public:
	using Ptr = std::shared_ptr<Render::Texture>;

	Texture( void)		= delete;
	Texture( Texture&)	= delete;
	Texture( Texture&&)	= delete;
	Texture( std::string filename);
	~Texture( void);

	Texture& operator=( const Texture&)	= delete;

	void	bind	( void) const;
};

}; // namespace Render
#endif // TEXTURE_H
