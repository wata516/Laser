#include <Laser/Common/Resource/ResourceManager.h>
#include <Laser/Common/Resource/Buffer.h>
#include <Laser/Common/Resource/BufferFactory.h>
#include <TGUL/String.h>
#include <map>

namespace Laser
{
	class ResourceManager::Impl
	{
		std::map< Resource::Buffer *, boost::shared_ptr< Resource::Buffer > > mBuffers;
	};
		
	bool ResourceManager::CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const
	{
		return Resource::BufferFactory::Create( name, ppBuffer );
	}
}