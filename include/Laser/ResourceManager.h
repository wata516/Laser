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
	class IShader;

	class ResourceManager : IResourceManager
	{
	public:
		bool CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const;
		virtual bool CreateShader( const TGUL::String &name, IShader **ppShader ) const = 0;
	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
