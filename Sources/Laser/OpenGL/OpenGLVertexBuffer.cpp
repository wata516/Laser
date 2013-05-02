#include "OpenGLVertexBuffer.h"
#include <Laser/VertexDeclare.h>
#include <Laser/Exception.h>
#include <boost/numeric/conversion/converter.hpp>
#include <boost/scoped_array.hpp>
#include <boost/foreach.hpp>

namespace Laser
{
	const boost::array< GLenum, IVertexDeclare::TYPE_MAX > gVertexType = {
		GL_FLOAT,
		GL_FLOAT,
		GL_FLOAT
	};
	
	const boost::array< GLenum, IVertexDeclare::TYPE_MAX > gVertexArraySize = {
		4,
		4,
		2
	};

	OpenGLVertexBuffer::OpenGLVertexBuffer( )
	: mHandle( 0 )
	{ }

	bool OpenGLVertexBuffer::Write( WriteType WriteFunction )
	{
		mVertexBuffers = boost::shared_array<GLuint>( new GLuint[mDeclare.GetElementNum()] );
		
		GLint GLElementSize;
		
		try { 
			GLElementSize = boost::numeric::converter< GLint, size_t >::convert( mDeclare.GetElementNum() );
		} catch( std::exception const& ) {
			ASSERT( 0, "numeric cast exception." );
			return false;
		}
		
		glGenBuffers( GLElementSize, mVertexBuffers.get() );

		for( GLint i = 0 ; i < GLElementSize ; ++ i ) {
			if( mVertexBuffers[i] == 0 ) {
				return false;
			}
		}

		// バッファに書き込む
		size_t BufferSize = mDeclare.GetSize() * mVertexNum;
		boost::scoped_array< char > pTempolary( new char[ BufferSize ] );

		size_t WriteSize = 0;

		WriteSize = WriteFunction( pTempolary.get(), mVertexNum );
		
		EXCEPT( WriteSize > BufferSize, Exception::EXCEPTION_INVALIED_ACCESS , "VertexBuffer Write Over.", "" );

		char *pCurrent = pTempolary.get();
		for( size_t i = 0 ; i < mDeclare.GetElementNum() ; ++ i ) {

			IVertexDeclare::TYPE type;
			if( mDeclare.GetVertexType( i, &type ) ) {
				size_t BufferSize = mDeclare.GetTypeVertexSize(type) * mVertexNum;

				glBindBuffer( GL_ARRAY_BUFFER, mVertexBuffers[i] );
				glBufferData( GL_ARRAY_BUFFER, BufferSize, pCurrent, GL_STATIC_DRAW );
				
				pCurrent += BufferSize;
			}
		}

		glGenVertexArrays( 1, &mHandle );
		glBindVertexArray( mHandle );

		for( size_t i = 0 ; i < mDeclare.GetElementNum() ; ++ i ) {
			const VertexDeclare::VertexElement *pElm = mDeclare.GetElement( i );
			IVertexDeclare::TYPE type;
			if( mDeclare.GetVertexType( i, &type ) ) {
				if( pElm != 0 ) {
					glBindBuffer( GL_ARRAY_BUFFER, mVertexBuffers[i] );
					glVertexAttribPointer(pElm->Locate, gVertexArraySize[type], gVertexType[type], GL_FALSE, 0, 0);
					glEnableVertexAttribArray( pElm->Locate );
				}
			}
		}
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return true;
	}

	bool OpenGLVertexBuffer::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN || uuid == UUIDS::OPENGL_VERTEX_BUFFER ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}

}