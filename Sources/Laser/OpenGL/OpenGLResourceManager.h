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
	class Texture;
	class RenderTarget;
	class VertexBuffer;
	class IndexBuffer;
	class ShaderUniformBuffer;

	class OpenGLResourceManager : public ResourceManager
	{
	public:
		virtual bool CreateVertexBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, VertexBuffer **ppBuffer );
		virtual bool CreateIndexBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, IndexBuffer **ppBuffer );
		virtual bool CreateUniformBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer );
		virtual bool CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader );
		virtual bool CreateTexture( const TGUL::String &CreateName, const TGUL::String &TextureName, Texture **ppBuffer );
		virtual bool CreateRenderTarget( const TGUL::String &CreateName, const TGUL::String &RenderTargetName, RenderTarget **ppRenderTarget );
	};
}