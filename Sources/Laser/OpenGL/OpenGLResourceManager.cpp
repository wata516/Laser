#include "OpenGLResourceManager.h"
#include "OpenGLShaderFactory.h"

namespace Laser
{
	bool OpenGLResourceManager::CreateShader( const TGUL::String &name, Shader **ppShader )
	{
		bool result = OpenGLShaderFactory::Create( name, ppShader );
		
		if( result ) {
			AddShader( **ppShader );
		}
		
		return result;
	}
}
