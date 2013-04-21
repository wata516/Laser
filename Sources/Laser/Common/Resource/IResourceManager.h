#pragma once

#include <Laser/Common/System/Object.h>

namespace Laser
{
	class IResourceManager : public Object
	{
	public:
		static const UUID &GetUUID( ) { return UUIDS::RESOURCE_IMANAGER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );
	};

	bool IResourceManager::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::OBJECT || uuid == UUIDS::IUNKNOWN) {
			*ppObject = this;
			return true;
		}

		return false;
	}
}