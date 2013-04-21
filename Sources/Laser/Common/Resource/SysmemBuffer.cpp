#include <Laser/Common/Resource/SysmemBuffer.h>

namespace Laser
{
	namespace Resource
	{
		SysmemBuffer::SysmemBuffer()
		: mVertexSize( 0 )
		, mArrayNum( 0 )
		{ }

		SysmemBuffer::~SysmemBuffer()
		{ }

		bool SysmemBuffer::Allocate( size_t VertexSize, size_t ArrayNum )
		{
			mVertexSize = VertexSize;
			mArrayNum = ArrayNum;

			mMemory = boost::shared_array< uint8_t >( new uint8_t[ mVertexSize * mArrayNum ] );

			if( mMemory == 0 ) {
				return false;
			}

			return true;
		}

		bool SysmemBuffer::Write( WriteType WriteFunction )
		{
			uint8_t *pCurrent = mMemory.get();
			
			for( size_t i = 0 ; i < mArrayNum ; ++ i ) {
				WriteFunction( pCurrent, mVertexSize, i );
				pCurrent += mVertexSize;
			}
			
			return true;
		}

		bool SysmemBuffer::QueryInterface( const UUID &uuid, void **ppObject )
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
