#pragma once

#include <Laser/Common/System/UUID.h>

namespace Laser
{
	namespace System
	{
		class IUnknown
		{
		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::IUNKNOWN; }
			virtual unsigned int AddRef( ) = 0;
			virtual unsigned int Release( ) = 0;
			virtual bool QueryInterface( const UUID &uuid, void **ppObject ) = 0;
		};
	}
}