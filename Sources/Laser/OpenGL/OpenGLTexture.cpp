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

		UpdateParameter( true );

		ilDeleteImages(1, &mImgId );
		glBindTexture( GL_TEXTURE_2D, 0 );

		mAvailable = true;

		return true;
	}

	void OpenGLTexture::UpdateParameter( bool all )
	{
		if( all ) {
			mUpdate.reset();
			mUpdate.flip();
		}

		if( mUpdate.any() ) {
			glBindTexture( GL_TEXTURE_2D, mTexId );
		}

		if( mUpdate[UPDATE_MIN_FILTER] ) {
			boost::array< GLenum, MIN_FILTER_MAX > filters = {
				GL_NEAREST,
				GL_LINEAR,
				GL_NEAREST_MIPMAP_NEAREST,
				GL_LINEAR_MIPMAP_NEAREST,
				GL_NEAREST_MIPMAP_LINEAR,
				GL_LINEAR_MIPMAP_LINEAR
			};
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filters[ mMinFilter ]);
			mUpdate[ UPDATE_MIN_FILTER ] = 0;
		}

		if( mUpdate[UPDATE_MAG_FILTER] ) {
			boost::array< GLenum, MAG_FILTER_MAX > mags = {
				GL_NEAREST,
				GL_LINEAR,
			};
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mags[ mMagFilter ] );
			mUpdate[ UPDATE_MAG_FILTER ] = 0;
		}

		if( mUpdate[UPDATE_WRAP] ) {
			boost::array< GLenum, WRAP_MAX > wraps = {
				GL_CLAMP_TO_EDGE,
				GL_CLAMP_TO_BORDER,
				GL_MIRRORED_REPEAT,
				GL_REPEAT
			};
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wraps[ mWrapS ] );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wraps[ mWrapT ] );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, wraps[ mWrapR ] );
			mUpdate[ UPDATE_WRAP ] = 0;
		}

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