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
		virtual bool Read( const TGUL::String &FileName );
		virtual bool Compile( const TGUL::String &source );
		virtual bool Load( );
	};
}