
#include "OpenGLCommandVertexBuffer.h"
#include "OpenGLVertexBuffer.h"
#include <Laser/UUID.h>

namespace Laser
{
	namespace Command
	{
		OpenGLVertexBuffer::OpenGLVertexBuffer()
		:mVertexBuffer(0)
		{}

		bool OpenGLVertexBuffer::Create( Laser::VertexBuffer *pVertexBuffer )
		{
			void *pGLBuffer = 0;
			if( pVertexBuffer->QueryInterface( UUIDS::OPENGL_VERTEX_BUFFER, &pGLBuffer ) ) {
				mVertexBuffer = static_cast< Laser::OpenGLVertexBuffer * >( pGLBuffer );
				
				return true;
			}
			
			return false;
		}
		
		void OpenGLVertexBuffer::Draw()
		{
			if( mVertexBuffer ) {
				glBindVertexArray( mVertexBuffer->GetHandle() );
				glDrawArrays( GL_TRIANGLES, 0, 3 );
			}
		}
	}
}