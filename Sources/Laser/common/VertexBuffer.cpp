#include <Laser/VertexBuffer.h>
#include <Laser/VertexDeclare.h>
#include <Laser/Exception.h>

namespace Laser
{
	VertexBuffer::VertexBuffer()
	: mVertexNum( 0 )
	{ }

	VertexBuffer::~VertexBuffer()
	{ }
	
	bool VertexBuffer::Create( const VertexDeclare &declare, size_t VertexNum )
	{
		mDeclare = declare;
		mVertexNum = VertexNum;

		return true;
	}

	bool VertexBuffer::Write( WriteType WriteFunction )
	{
		return false;
	}

	bool VertexBuffer::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == Object::GetUUID() ||
			uuid == Buffer::GetUUID() || uuid == VertexBuffer::GetUUID() ) {
				*ppObject = this;
				return true;
		}

		return false;
	}
}
