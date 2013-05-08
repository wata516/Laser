#include "OpenGLCommandPrimitive.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLVertexBuffer.h"

namespace Laser
{
	namespace Command
	{
		OpenGLPrimitive::OpenGLPrimitive()
			: mIndexBuffer( 0 )
			, mVertexBuffer( 0 )
			, mTopology( GL_POINTS )
		{ }

		bool OpenGLPrimitive::Create( Laser::IndexBuffer *pIndexBuffer, Laser::VertexBuffer *pVertexBuffer, Topology topology )
		{
			void *pGLBuffer = 0;
			if( pIndexBuffer ) {
				if( pIndexBuffer->QueryInterface( UUIDS::OPENGL_INDEX_BUFFER, &pGLBuffer ) == false ) {
					return false;
				}
				mIndexBuffer = static_cast< Laser::OpenGLIndexBuffer * >( pGLBuffer );
			}

			if( pVertexBuffer->QueryInterface( UUIDS::OPENGL_VERTEX_BUFFER, &pGLBuffer ) == false ) {
				return false;
			}
			mVertexBuffer = static_cast< Laser::OpenGLVertexBuffer * >( pGLBuffer );

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
			mTopology = topologies[ topology ];

			return true;
		}

		void OpenGLPrimitive::Draw( DrawStatus &Status )
		{
			GLsizei VertexNum = static_cast< GLsizei >( mVertexBuffer->GetVertexNum() );

			if( mVertexBuffer && mIndexBuffer ) {
				glBindBuffer( GL_ARRAY_BUFFER, mVertexBuffer->GetHandle() );
				glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer->GetHandle() );
				glDrawElements( mTopology, VertexNum, GL_UNSIGNED_SHORT, 0 );
			}

			if( mVertexBuffer && !(mIndexBuffer) ) {
				glBindVertexArray( mVertexBuffer->GetHandle() );
				glDrawArrays( mTopology, 0, VertexNum );
			}
		}
	}
}
