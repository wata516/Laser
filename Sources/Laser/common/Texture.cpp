#include <Laser/Texture.h>

namespace Laser
{
	Texture::Texture()
	: mStatus( STATUS_NONE )
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

}