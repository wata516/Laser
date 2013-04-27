#pragma once

#include <Laser/ResourceManager.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resoure
	{
		class Buffer;
	}
	class Shader;

	class OpenGLResourceManager : public ResourceManager
	{
	public:
		virtual bool CreateBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, Resource::Buffer **ppBuffer );
		virtual bool CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader );
	};
}