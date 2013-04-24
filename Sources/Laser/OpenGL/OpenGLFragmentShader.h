#pragma once

#include <laser/Shader.h>

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
	};
}