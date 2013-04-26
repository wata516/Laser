#pragma once

#include <Laser/Shader.h>
#include <GL/glew.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class OpenGLFragmentShader : public Shader
	{
	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );
		
	protected:
		bool ReadComplete( void *pBuffer, size_t BufferSize );
		
	private:
		Status mStatus;
		GLuint mShader;
	};
}