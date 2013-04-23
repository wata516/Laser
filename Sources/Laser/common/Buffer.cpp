#include <Laser/Buffer.h>

#include <Laser/Exception.h>
#include <TGUL/String.h>
#include <boost/shared_array.hpp>
#include <fstream>

namespace Laser
{
	namespace Resource
	{
		class Buffer::Impl
		{
			Buffer::Status mStatus;
			size_t mReadSize;			//!< 1回に読み込むサイズ
			std::ifstream mIFStream;
			TGUL::String mFileName;
			size_t mFileSize;
			boost::shared_array<char> mBuffer;

		public:
			Impl( )
			: mStatus( Buffer::STATUS_NONE )
			{}
			
			bool Execute( );
			
		public:
			bool ReadStart( const TGUL::String &FileName, size_t ReadSize );
		};

		bool Buffer::Impl::Execute()
		{
			if( mStatus == Buffer::STATUS_READ ) {
				if( mIFStream.is_open() == false ) {
					
					mIFStream.open( mFileName.c_str() );
					if( mIFStream.fail() ) {
						mStatus = Buffer::STATUS_NONE;
						return false;
					}
					mFileSize = mIFStream.seekg(0, std::ios::end).tellg();
					mIFStream.seekg(0, std::ios::beg);
					mBuffer.reset( new char[ mFileSize ] );

				} else {
					if( mIFStream.good() == false ) {
						mIFStream.close();
						mStatus = Buffer::STATUS_NONE;
						return false;
					}

					mIFStream.read( &mBuffer[ mIFStream.tellg() ], mReadSize );
					if( mIFStream.bad() ) {
						mIFStream.close();
						mStatus = Buffer::STATUS_NONE;
						return false;
					}
				}
			}

			return true;
		}
		
		bool Buffer::Impl::ReadStart( const TGUL::String &FileName, size_t ReadSize )
		{
			mStatus = Buffer::STATUS_READ;
			mReadSize = ReadSize;
			mFileName = FileName;

			return true;
		}
		
		bool Buffer::QueryInterface( const UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == Object::GetUUID()) {
				*ppObject = this;
				return true;
			}

			return false;
		}
		Buffer::Buffer()
		: mImpl( new Impl )
		{}
		
		bool Buffer::Execute( )
		{
			return mImpl->Execute();
		}
	}
}
