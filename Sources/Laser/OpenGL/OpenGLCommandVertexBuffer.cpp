
#include "OpenGLCommandVertexBuffer.h"
#include "OpenGLVertexBuffer.h"
#include <Laser/UUID.h>

namespace Laser
{
	namespace Command
	{
		OpenGLVertexBuffer::OpenGLVertexBuffer()
		: mVertexBuffer(0)
		, mTopology( GL_TRIANGLES )
		{}

		bool OpenGLVertexBuffer::Create( Laser::VertexBuffer *pVertexBuffer, Topology topology )
		{
			boost::array< GLenum, TOPOLOGY_MAX > topologies = {
				GL_POINTS,
				GL_LINE_STRIP,
				GL_LINE_LOOP,
				GL_LINES,
				GL_LINE_STRIP_ADJACENCY,
				GL_LINES_ADJACENCY,
				GL_TRIANGLE_STRIP,
				GL_TRIANGLE_FAN,
				GL_TRIANGLES,
				GL_TRIANGLE_STRIP_ADJACENCY,
				GL_TRIANGLES_ADJACENCY
			};

			void *pGLBuffer = 0;
			if( pVertexBuffer->QueryInterface( UUIDS::OPENGL_VERTEX_BUFFER, &pGLBuffer ) ) {
				mVertexBuffer = static_cast< Laser::OpenGLVertexBuffer * >( pGLBuffer );
				
				mTopology = topologies[ topology ];

				return true;
			}
			
			return false;
		}
		
		void OpenGLVertexBuffer::Draw( DrawStatus &Status )
		{
			if( mVertexBuffer ) {
				glBindVertexArray( mVertexBuffer->GetHandle() );
				glDrawArrays( mTopology, 0, static_cast< GLsizei >( mVertexBuffer->GetVertexNum() ) );
			}
		}
	}
}