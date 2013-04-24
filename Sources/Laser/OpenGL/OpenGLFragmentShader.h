#pragma once

#include <laser/IShader.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class OpenGLFragmentShader : public IShader
	{
	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );
	};
}