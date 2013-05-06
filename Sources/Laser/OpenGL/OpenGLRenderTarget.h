#pragma once

#include <Laser/RenderTarget.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLRenderTarget : public RenderTarget
	{
	public:
		OpenGLRenderTarget();

	public:
		static const UUID &GetUUID( ) { return UUIDS::OPENGL_RENDER_TARGET; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Create( unsigned int width, unsigned int height );
		virtual bool IsAvailable() const;
		GLenum GetAttachment( ) const { return mAttachment; }
		virtual GLuint GetHandle() const { return mColor; }

	private:
		bool mAvailable;
		GLuint mHandle;
		GLuint mColor;
		GLenum mAttachment;
		
	};
}
