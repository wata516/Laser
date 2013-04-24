#pragma once

#include <Laser/IResourceManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace Resource
	{
		class Buffer;
	}
}

namespace TGUL
{
	class String;
}

namespace Laser
{
	class Shader;

	class ResourceManager : IResourceManager
	{
	public:
		ResourceManager();

	public:
		bool CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const;
		virtual bool CreateShader( const TGUL::String &name, Shader **ppShader ) = 0;
		
		void Execute();

	protected:
		void AddShader( Shader &shader );

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
