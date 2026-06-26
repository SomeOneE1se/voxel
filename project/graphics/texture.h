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

#include "uni_base_types.h"

namespace Render {

/**
 * @brief The Texture class
 ******************************************************************************/
class Texture
{
	TInt	width;
	TInt	height;
	TUInt32	id;

	Texture( std::string filename);

public:
	using Ptr	= TShared<Texture>;

	Texture( void)				= delete;
	Texture( const Texture&)	= delete;
	Texture( Texture&&)			= delete;
	~Texture( void);

	Texture& operator=( const Texture&)	= delete;
	Texture& operator=( Texture&&)		= delete;

	static Texture::Ptr create( std::string filename);

	void	bind	( void) const;
};

}; // namespace Render
#endif // TEXTURE_H
