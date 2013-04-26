#pragma once

#include "OpenGLShader.h"
#include <GL/glew.h>

namespace Laser
{
	class OpenGLVertexShader : public OpenGLShader
	{
	public:
		OpenGLVertexShader();

	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );

	protected:
		bool ReadComplete( void *pBuffer, size_t BufferSize );

	public:
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	private:
		Status mStatus;
		GLuint mShader;
	};
}