#include "OpenGLCommandIndexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include <Laser/UUID.h>

namespace Laser
{
	namespace Command
	{
		OpenGLIndexBuffer::OpenGLIndexBuffer()
			: mIndexBuffer(0)
		{}

		bool OpenGLIndexBuffer::Create( Laser::IndexBuffer *pIndexBuffer )
		{
			void *pGLBuffer = 0;
			if( pIndexBuffer->QueryInterface( UUIDS::OPENGL_INDEX_BUFFER, &pGLBuffer ) ) {
				pIndexBuffer = static_cast< Laser::OpenGLIndexBuffer * >( pGLBuffer );

				return true;
			}

			return false;
		}

		void OpenGLIndexBuffer::Draw( DrawStatus &Status )
		{
			if( mIndexBuffer ) {
				glBindVertexArray( mIndexBuffer->GetHandle() );
			}
		}
	}
}