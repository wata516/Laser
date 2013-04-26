#include <Laser/Shader.h>

namespace Laser
{
	bool Shader::IsAvailable( ) const
	{
		if( GetStatus() == Buffer::STATUS_NORMAL ) {
			return true;
		}

		return true;
	}
}
