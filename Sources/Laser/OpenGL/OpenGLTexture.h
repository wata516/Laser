#pragma once

#include <Laser/Texture.h>
#include <TGUL/String.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLTexture : public Texture
	{
	public:
		OpenGLTexture();

	public:
		virtual bool ReadComplete( void *pBuffer, size_t BufferSize );
		virtual bool IsAvailable() const;
		
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		GLuint GetHandle() const { return mTexId; }
		void SetName( const TGUL::String &name ) { mName = name; }
		const TGUL::String &GetName( ) const { return mName; }

	private:
		bool mAvailable;
		GLuint mTexId;
		TGUL::String mName;
	};
}
