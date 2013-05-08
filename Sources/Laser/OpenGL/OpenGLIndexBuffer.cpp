#include "OpenGLIndexBuffer.h"
#include <Laser/Exception.h>
#include <boost/array.hpp>
#include <boost/scoped_array.hpp>

namespace Laser
{
	OpenGLIndexBuffer::OpenGLIndexBuffer()
		: mIndexSize( INDEX_SIZE_MAX )
		, mBuffer( 0 )
		, mIndexNum( 0 )
	{ }

	bool OpenGLIndexBuffer::Create( IndexSize type, unsigned int IndexNum )
	{
		mIndexSize = type;
		mIndexNum = IndexNum;

		glGenBuffers( 1, &mBuffer );
		
		return true;
	}

	bool OpenGLIndexBuffer::Write( WriteType WriteFunction )
	{
		boost::array< int , INDEX_SIZE_MAX > indexsize = {
			2,
			4
		};
		size_t BufferSize = indexsize[ mIndexSize ] * mIndexNum;
		boost::scoped_array< char > pTempolary( new char[ BufferSize ] );

		size_t WriteSize = 0;

		WriteSize = WriteFunction( pTempolary.get(), mIndexNum );

		EXCEPT( WriteSize > BufferSize, Exception::EXCEPTION_INVALIED_ACCESS , "VertexBuffer Write Over.", "" );

		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mBuffer );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, BufferSize, pTempolary.get(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return true;
	}
	
	bool OpenGLIndexBuffer::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN || uuid == UUIDS::OPENGL_INDEX_BUFFER ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}

}
