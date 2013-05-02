#include <Laser/Texture.h>

namespace Laser
{
	Texture::Texture()
	: mStatus( STATUS_NONE )
	, mMinFilter( MIN_FILTER_NEAREST )
	, mMagFilter( MAG_FILTER_LINEAR )
	, mWrapS( WRAP_REPREAT )
	, mWrapT( WRAP_REPREAT )
	, mWrapR( WRAP_REPREAT )
	{}

	bool Texture::Load( const TGUL::String &FileName, size_t ReadSize )
	{
		bool result = ReadASync( FileName, ReadSize );
		
		if( result == false ) {
			mStatus = STATUS_NONE;
			return false;
		}
		mStatus = STATUS_FILE_READING;
		
		return result;
	}

	bool Texture::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == Object::GetUUID() ||
		   uuid == Buffer::GetUUID() || uuid == Texture::GetUUID() ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}
	
	void Texture::SetMinFilter( MinFilter Filter )
	{
		if( (mMinFilter != Filter) ) {
			mMinFilter = Filter;
			mUpdate[ UPDATE_MIN_FILTER ] = 1;
		}
	}

	void Texture::SetMagFilter( MagFilter Filter )
	{
		if( mMagFilter != Filter ) {
			mMagFilter = Filter;
			mUpdate[ UPDATE_MAG_FILTER ] = 1;
		}
	}
	
	void Texture::SetWrap( Wrap s, Wrap t, Wrap r )
	{
		if( ( mWrapS != s ) || (mWrapT != t ) || (mWrapR != r ) ) {
			mWrapS = s;
			mWrapT = t;
			mWrapR = r;
			mUpdate[ UPDATE_WRAP ] = 1;
		}
	}


}