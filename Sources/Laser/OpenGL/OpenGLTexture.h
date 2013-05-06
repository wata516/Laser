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

		static const UUID &GetUUID( ) { return UUIDS::OPENGL_TEXTURE; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		virtual GLuint GetHandle() const { return mTexId; }

		void SetName( const TGUL::String &name ) { mName = name; }
		const TGUL::String &GetName( ) const { return mName; }
		void UpdateParameter( bool all );

	private:
		bool mAvailable;
		GLuint mTexId;
		TGUL::String mName;
	};
}
