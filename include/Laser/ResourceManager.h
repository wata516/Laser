#pragma once

#include <Laser/IResourceManager.h>
#include <boost/shared_ptr.hpp>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class Shader;
	class Buffer;
	class Texture;
	class RenderTarget;
	class VertexBuffer;
	class IndexBuffer;
	class ShaderUniformBuffer;

	class ResourceManager : IResourceManager
	{
	public:
		ResourceManager();

	public:
		virtual bool CreateVertexBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, VertexBuffer **ppBuffer ) = 0;
		virtual bool CreateIndexBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, IndexBuffer **ppBuffer ) = 0;
		virtual bool CreateUniformBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer ) = 0;
		virtual bool CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader ) = 0;
		virtual bool CreateTexture( const TGUL::String &CreateName, const TGUL::String &TextureName, Texture **ppBuffer ) = 0;
		virtual bool CreateRenderTarget( const TGUL::String &CreateName, const TGUL::String &RenderTargetName, RenderTarget **ppRenderTarget ) = 0;
		void Execute();

	public:
		bool GetVertexBuffer( const TGUL::String &BufferName, VertexBuffer **ppBuffer ) const;
		bool GetIndexBuffer( const TGUL::String &BufferName, IndexBuffer **ppBuffer ) const;
		bool GetUniformBuffer( const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer ) const;
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;
		bool GetTexture( const TGUL::String &BufferName, Texture **ppTexture ) const;
		bool GetRenderTarget( const TGUL::String &BufferName, RenderTarget **ppRenderTarget ) const;
		

	protected:
		bool AddVertexBuffer( const TGUL::String &name, VertexBuffer &buffer );
		bool AddIndexBuffer( const TGUL::String &name, IndexBuffer &buffer );
		bool AddUniformBuffer( const TGUL::String &name, ShaderUniformBuffer &uniform );
		bool AddShader( const TGUL::String &name, Shader &shader );
		bool AddTexture( const TGUL::String &name, Texture &texture );
		bool AddRenderTarget( const TGUL::String &name, RenderTarget &RenderTarget );

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
