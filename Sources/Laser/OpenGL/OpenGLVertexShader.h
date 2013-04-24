#pragma once

#include <Laser/Shader.h>

namespace Laser
{
	class OpenGLVertexShader : public Shader
	{
	public:
		OpenGLVertexShader();

	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );

	protected:
		bool ReadComplete( void *pBuffer, size_t BufferSize );

	private:
		Status mStatus;
	};
}