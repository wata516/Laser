#pragma once

#include <Laser/Object.h>

namespace Laser
{
	class IResourceManager : public Object
	{
	public:
		static const UUID &GetUUID( ) { return UUIDS::RESOURCE_IMANAGER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );
	};
}