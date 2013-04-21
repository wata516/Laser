#pragma once

#include <Laser/Common/Resource/IResourceManager.h>
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
	class ResourceManager : IResourceManager
	{
	public:
		bool CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const;

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
