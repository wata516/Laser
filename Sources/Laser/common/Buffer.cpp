#include <Laser/Buffer.h>

namespace Laser
{
	namespace Resource
	{
		bool Buffer::QueryInterface( const UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == Object::GetUUID()) {
				*ppObject = this;
				return true;
			}

			return false;
		}
		Buffer::Buffer()
		: mStatus( STATUS_NONE )
		{}
	}
}
