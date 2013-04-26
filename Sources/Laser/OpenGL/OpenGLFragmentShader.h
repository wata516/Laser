#pragma once

#include <OpenGLShader.h>
#include <GL/glew.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class OpenGLFragmentShader : public OpenGLShader
	{
	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );
		
	protected:
		bool ReadComplete( void *pBuffer, size_t BufferSize );

	public:
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );
	private:
		Status mStatus;
	};
}