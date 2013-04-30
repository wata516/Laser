#include <Laser/ShaderUniformBuffer.h>

namespace Laser
{
	bool ShaderUniformBuffer::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == Object::GetUUID() ||
		   uuid == Buffer::GetUUID() || uuid == ShaderUniformBuffer::GetUUID() ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}
}