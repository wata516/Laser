#include "OpenGLTexture.h"
#include <Laser/Exception.h>
#include <IL/il.h>
#include <boost/numeric/conversion/converter.hpp>
#include <boost/array.hpp>

namespace Laser
{
	OpenGLTexture::OpenGLTexture()
	: mAvailable( false )
	, mTexId( 0 )
	{}
	
	bool OpenGLTexture::ReadComplete( void *pBuffer, size_t BufferSize )
	{
		mAvailable = false;
		ILuint mImgId;

		ilGenImages(1, &mImgId);
		
		ilBindImage(mImgId);
		
		ILuint BufferSizeIL;
		try {
			BufferSizeIL = boost::numeric::converter< ILuint, size_t >::convert( BufferSize );
		} catch( std::exception const& ) {
			ASSERT( 0, "numeric cast exception." );
			return false;
		}

		if( ilLoadL( IL_TYPE_UNKNOWN, pBuffer, BufferSizeIL ) == false ) {
			return false;
		}
		
		GLsizei width = 0, height = 0;
		try {
			width = boost::numeric::converter< GLsizei, ILint >::convert( ilGetInteger(IL_IMAGE_WIDTH) );
			height = boost::numeric::converter< GLsizei, ILint >::convert( ilGetInteger(IL_IMAGE_HEIGHT) );
		} catch( std::exception const& ) {
			ASSERT( 0, "numeric cast exception." );
			return false;
		}
		ILint PixelPerBytes = ilGetInteger( IL_IMAGE_BYTES_PER_PIXEL ) - 1;
		ILint PixelDepth = ilGetInteger(IL_IMAGE_DEPTH) - 1;

		boost::array< GLenum, 4 > Depths = {
			GL_UNSIGNED_BYTE,
			GL_UNSIGNED_SHORT,
			GL_UNSIGNED_INT,
			GL_FLOAT
		};
		boost::array< GLenum, 4 > PixelPerTypes = {
			GL_LUMINANCE,
			GL_LUMINANCE_ALPHA,
			GL_RGB,
			GL_RGBA
		};
		
		GLubyte *pImage = static_cast< GLubyte * >( ilGetData() );

		glGenTextures( 1, &mTexId );
		
		glBindTexture( GL_TEXTURE_2D, mTexId );
		
		glTexImage2D( GL_TEXTURE_2D, 0, PixelPerTypes[ PixelPerBytes ], width, height, 0, PixelPerTypes[ PixelPerBytes ], Depths[ PixelDepth ], pImage );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		ilDeleteImages(1, &mImgId );

		mAvailable = true;

		return true;
	}

	bool OpenGLTexture::IsAvailable() const
	{
		return mAvailable;
	}

	bool OpenGLTexture::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN || uuid == UUIDS::OPENGL_TEXTURE ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}


}