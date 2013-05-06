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
	
	bool OpenGLResourceManager::CreateBuffer( const TGUL::String &CreateName, const TGUL::String &VertexBufferName, Resource::Buffer **ppBuffer )
	{
		bool result = OpenGLBufferFactory::Create( CreateName, ppBuffer );
		
		if( result ) {
			return AddBuffer( VertexBufferName, **ppBuffer );
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
