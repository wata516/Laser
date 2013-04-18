#pragma once

#include <Laser/Common/Resource/Buffer.h>
#include <Laser/Common/System/UUID.h>

namespace Laser
{
	namespace Resource
	{
		class SysmemBuffer : public Buffer
		{
		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::SYSMEMBUFFER; }
			virtual bool QueryInterface( const System::UUID &uuid, void **ppObject );
		};
		bool SysmemBuffer::QueryInterface( const System::UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == Object::GetUUID() ||
			   uuid == Buffer::GetUUID() || uuid == SysmemBuffer::GetUUID() ) {
				*ppObject = this;
				return true;
			}
			
			return false;
		}
	}
}
