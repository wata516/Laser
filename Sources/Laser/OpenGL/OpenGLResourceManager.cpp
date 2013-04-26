#include "OpenGLResourceManager.h"
#include "OpenGLShaderFactory.h"

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
}
