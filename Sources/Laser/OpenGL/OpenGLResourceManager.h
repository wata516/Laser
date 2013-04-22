#pragma once

#include <Laser/ResourceManager.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class IShader;

	class OpenGLResourceManager : public ResourceManager
	{
	public:
		virtual bool CreateShader( const TGUL::String &name, IShader **ppShader ) const;
	};
}