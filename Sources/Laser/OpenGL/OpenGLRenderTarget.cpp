#include "OpenGLRenderTarget.h"

namespace Laser
{
	OpenGLRenderTarget::OpenGLRenderTarget( )
	: mAvailable(false)
	, mHandle(0)
	, mColor(0)
	, mAttachment( 0 )
	{
	}

	bool OpenGLRenderTarget::Create( unsigned int width, unsigned int height )
	{
		mAttachment = GL_COLOR_ATTACHMENT0;

		glGenFramebuffers(1, &mHandle );
		
		glBindFramebuffer( GL_FRAMEBUFFER, mHandle );

		glGenTextures( 1, &mColor );
		glActiveTexture( GL_TEXTURE0);
		glBindTexture( GL_TEXTURE_2D, mColor );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glFramebufferTexture2D( GL_FRAMEBUFFER, mAttachment, GL_TEXTURE_2D, mColor, 0 );

		glBindTexture( GL_TEXTURE_2D, 0 );

		mAvailable = true;

		return true;
	}

	bool OpenGLRenderTarget::IsAvailable() const
	{
		return mAvailable;
	}

	bool OpenGLRenderTarget::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == Object::GetUUID() ||
		   uuid == Buffer::GetUUID() || uuid == OpenGLRenderTarget::GetUUID() ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}

}
