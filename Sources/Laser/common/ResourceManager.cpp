#include <Laser/ResourceManager.h>
#include <Laser/Buffer.h>
#include "BufferFactory.h"
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

	bool IResourceManager::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::OBJECT || uuid == UUIDS::IUNKNOWN) {
			*ppObject = this;
			return true;
		}

		return false;
	}

}