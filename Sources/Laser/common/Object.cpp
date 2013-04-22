#include <Laser/Object.h>

namespace Laser
{
	bool Object::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN) {
			*ppObject = this;
			return true;
		}

		return false;
	}
}