#include "OpenGLResourceManager.h"
#include "OpenGLShaderFactory.h"

namespace Laser
{
	bool OpenGLResourceManager::CreateShader( const TGUL::String &name, IShader **ppShader ) const
	{
		return OpenGLShaderFactory::Create( name, ppShader );
	}
}
