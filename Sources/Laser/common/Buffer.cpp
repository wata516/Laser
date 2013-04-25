#include <Laser/Buffer.h>

#include <Laser/Exception.h>
#include <TGUL/String.h>
#include <boost/shared_array.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/optional.hpp>
#include <fstream>

namespace Laser
{
	namespace Resource
	{
		class Buffer::Impl
		{
		public:
			enum Status {
				STATUS_OK,
				STATUS_ERROR,
				STATUS_CALL_READ_COMPLETE
			};
			typedef boost::optional< Status > ExecuteResoultType;

		public:
			Impl( )
			: mStatus( Buffer::STATUS_NONE )
			{}
			
			ExecuteResoultType Execute( );
			
		public:
			bool ReadASync( const TGUL::String &FileName, size_t ReadSize );


		private:
			ExecuteResoultType NoneExecute();
			ExecuteResoultType ReadExecute();

		public:
			void *GetBuffer() { return mBuffer.get(); }
			size_t GetBufferSize() { return mBufferSize; }
		private:
			Buffer::Status mStatus;
			std::ifstream mIFStream;
			size_t mReadSize;			//!< 1回に読み込むサイズ
			TGUL::String mFileName;
			size_t mBufferSize;
			boost::shared_array< char > mBuffer;
		};

		Buffer::Impl::ExecuteResoultType Buffer::Impl::NoneExecute()
		{
			return boost::none;
		}

		Buffer::Impl::ExecuteResoultType Buffer::Impl::ReadExecute()
		{
			if( mIFStream.is_open() == false ) {

				mIFStream.open( mFileName.c_str(), std::ios::in | std::ios::binary  );
				if( mIFStream.fail() ) {
					mStatus = Buffer::STATUS_NONE;
					return STATUS_ERROR;
				}
				mBufferSize = mIFStream.seekg( 0, std::ios::end ).tellg();
				mIFStream.seekg(0, std::ios::beg);
				mBuffer.reset( new char[ mBufferSize ] );

			} else {
				if( mIFStream.good() == false ) {
					mIFStream.close();
					mStatus = Buffer::STATUS_NONE;
					return STATUS_ERROR;
				}
				size_t pos = mIFStream.tellg();
				mIFStream.read( &mBuffer[ pos ], mReadSize );
				if( mIFStream.bad() ) {
					mIFStream.close();
					mStatus = Buffer::STATUS_NONE;
					return STATUS_ERROR;
				}

				if( mIFStream.eof() ) {
					mStatus = Buffer::STATUS_NORMAL;
					return STATUS_CALL_READ_COMPLETE;
				}
			}

			return boost::none;
		}

		Buffer::Impl::ExecuteResoultType Buffer::Impl::Execute()
		{
			boost::array< boost::function< Buffer::Impl::ExecuteResoultType( ) >, Buffer::STATUS_MAX > functions = {
				boost::bind( &Impl::NoneExecute, this ),
				boost::bind( &Impl::ReadExecute, this ),
				boost::bind( &Impl::NoneExecute, this )
			};

			return functions[ mStatus ]();
		}
		
		bool Buffer::Impl::ReadASync( const TGUL::String &FileName, size_t ReadSize )
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
		
		bool Buffer::ReadASync( const TGUL::String &FileName, size_t ReadSize )
		{
			return mImpl->ReadASync( FileName, ReadSize );
		}
		bool Buffer::Execute( )
		{
			Buffer::Impl::ExecuteResoultType Result = mImpl->Execute();

			if( Result == Buffer::Impl::STATUS_CALL_READ_COMPLETE ) {
				return ReadComplete( mImpl->GetBuffer(), mImpl->GetBufferSize() );
			}

			return true;
		}
	}
}
