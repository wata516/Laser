#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resource {
		class Buffer;
	}

	class OpenGLBufferFactory
	{
	public:
		static bool Create( const TGUL::String &name, Resource::Buffer **ppShader );
	};
}