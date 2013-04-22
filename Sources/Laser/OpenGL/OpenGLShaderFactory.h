#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	class IShader;
	class OpenGLShaderFactory
	{
	public:
		static bool Create( const TGUL::String &name, IShader **ppShader );
	};
}