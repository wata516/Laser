#include "OpenGLResourceManager.h"
#include "OpenGLShaderFactory.h"
#include "OpenGLBufferFactory.h"

namespace Laser
{
	bool OpenGLResourceManager::CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader )
	{
		bool result = OpenGLShaderFactory::Create( CreateName, ppShader );
		
		if( result ) {
			return AddShader( ShaderName, **ppShader );
		}
		
		return result;
	}
	bool OpenGLResourceManager::CreateVertexBuffer( const TGUL::String &CreateName, const TGUL::String &VertexBufferName, VertexBuffer **ppBuffer )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, (Resource::Buffer**)ppBuffer );
		
		if( result ) {
			return AddVertexBuffer( VertexBufferName, **ppBuffer );
		}
		
		return result;
	}
	bool OpenGLResourceManager::CreateIndexBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, IndexBuffer **ppBuffer )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, (Resource::Buffer**)ppBuffer );

		if( result ) {
			return AddIndexBuffer( BufferName, **ppBuffer );
		}

		return result;
	}
	bool OpenGLResourceManager::CreateUniformBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, (Resource::Buffer**)ppBuffer );

		if( result ) {
			return AddUniformBuffer( BufferName, **ppBuffer );
		}

		return result;
	}

	bool OpenGLResourceManager::CreateTexture( const TGUL::String &CreateName, const TGUL::String &TextureName, Texture **ppTexture )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, (Resource::Buffer**)ppTexture );
		
		if( result ) {
			return AddTexture( TextureName, **ppTexture );
		}
		
		return result;		
	}

	bool OpenGLResourceManager::CreateRenderTarget( const TGUL::String &CreateName, const TGUL::String &RenderTargetName, RenderTarget **ppRenderTarget )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, (Resource::Buffer**)ppRenderTarget);

		if( result ) {
			return AddRenderTarget( RenderTargetName, **ppRenderTarget );
		}
		
		return result;
	}


}
