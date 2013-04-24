#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	class Shader;
	class OpenGLShaderFactory
	{
	public:
		static bool Create( const TGUL::String &name, Shader **ppShader );
	};
}