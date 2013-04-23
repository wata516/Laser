#pragma once

#include <Laser/IShader.h>

namespace Laser
{
	class OpenGLVertexShader : public IShader
	{
	public:
		virtual bool Read( const TGUL::String &FileName );
		
	};
}