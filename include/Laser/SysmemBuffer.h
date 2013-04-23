#pragma once

#include <Laser/Buffer.h>
#include <Laser/UUID.h>
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
			static const UUID &GetUUID( ) { return UUIDS::SYSMEMBUFFER; }
			virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		public:
			virtual bool Read( const TGUL::String &FileName ) { return false; }
			virtual bool Allocate( size_t VertexSize, size_t ArrayNum );
			virtual bool Write( WriteType WriteFunction );

		private:
			boost::shared_array< uint8_t > mMemory;
			size_t mVertexSize;
			size_t mArrayNum;
		};
	}
}
