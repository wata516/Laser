#pragma once

#include <Laser/Common/Resource/Buffer.h>
#include <Laser/Common/System/UUID.h>
#include <boost/shared_array.hpp>

namespace Laser
{
	namespace Resource
	{
		class SysmemBuffer : public Buffer
		{
		public:
			SysmemBuffer();
			~SysmemBuffer();

		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::SYSMEMBUFFER; }
			virtual bool QueryInterface( const System::UUID &uuid, void **ppObject );

		public:
			virtual bool Allocate( size_t size );

		private:
			boost::shared_array< uint8_t > mMemory;
		};
	}
}
