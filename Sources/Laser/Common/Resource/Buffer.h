#pragma once

#include <Laser/Common/System/Object.h>
#include <Laser/Common/System/UUID.h>
#include <boost/function.hpp>
#include <boost/shared_array.hpp>

namespace Laser
{
	namespace Resource
	{
		class Buffer : public Object
		{
		public:
			typedef boost::function< size_t( void *pAddress, size_t a, size_t n ) > WriteType;

		public:
			static const UUID &GetUUID( ) { return UUIDS::IBUFFER; }
			virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		public:
			virtual bool Allocate( size_t VertexSize, size_t ArrayNum ) { return false; }
			virtual bool Write( WriteType WriteFunction ) { return false; }
		};
	
		bool Buffer::QueryInterface( const UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == Object::GetUUID()) {
				*ppObject = this;
				return true;
			}
		
			return false;
		}
	}
}
