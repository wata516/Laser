#pragma once

#include <Laser/Common/System/Object.h>

namespace Laser
{
	namespace Resource
	{
		class IManager// : public System::Object
		{
		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::RESOURCE_IMANAGER; }
			virtual bool QueryInterface( const System::UUID &uuid, void **ppObject );
		};

		bool IManager::QueryInterface( const System::UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == System::UUIDS::OBJECT || uuid == System::UUIDS::IUNKNOWN) {
				*ppObject = this;
				return true;
			}
			
			return false;
		}

	}
}