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

}
