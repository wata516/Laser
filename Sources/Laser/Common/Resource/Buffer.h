#pragma once

#include <Laser/Common/System/Object.h>
#include <Laser/Common/System/UUID.h>

namespace Laser
{
	namespace Resource
	{
		class Buffer : public System::Object
		{
		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::IBUFFER; }
			virtual bool QueryInterface( const System::UUID &uuid, void **ppObject );

		public:
			virtual bool Allocate( size_t size ) { return false; };
		};
	
		bool Buffer::QueryInterface( const System::UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == Object::GetUUID()) {
				*ppObject = this;
				return true;
			}
		
			return false;
		}
	}
}
