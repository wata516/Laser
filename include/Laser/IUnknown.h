#pragma once

#include <Laser/UUID.h>

namespace Laser
{
		class IUnknown
		{
		public:
			static const UUID &GetUUID( ) { return UUIDS::IUNKNOWN; }
			virtual unsigned int AddRef( ) = 0;
			virtual unsigned int Release( ) = 0;
			virtual bool QueryInterface( const UUID &uuid, void **ppObject ) = 0;
		};
}