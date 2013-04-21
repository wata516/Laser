#include <Laser/Common/Resource/SysmemBuffer.h>
#include <Laser/Common/System/Exception.h>

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
			size_t TotalSize = 0;
			uint8_t *pCurrent = mMemory.get();
			
			for( size_t i = 0 ; i < mArrayNum ; ++ i ) {
				size_t MoveSize = WriteFunction( pCurrent, mVertexSize, i );
				pCurrent += MoveSize;
				TotalSize += MoveSize;

				EXCEPT( TotalSize >= mVertexSize, Exception::EXCEPTION_INVALIED_ACCESS , "SysemBuffer Write Over.", "" );
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
