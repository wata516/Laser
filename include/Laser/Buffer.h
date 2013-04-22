#pragma once

#include <Laser/Object.h>
#include <Laser/UUID.h>
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
	}
}
