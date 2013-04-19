#include <Laser/Common/Resource/SysmemBuffer.h>

namespace Laser
{
	namespace Resource
	{
		SysmemBuffer::SysmemBuffer()
		{ }

		SysmemBuffer::~SysmemBuffer()
		{ }

		bool SysmemBuffer::Allocate( size_t size )
		{
			mMemory = boost::shared_array< uint8_t >( new uint8_t[ size] );

			if( mMemory == 0 ) {
				return false;
			}

			return true;
		}

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
