#pragma once

#include <Laser/CommandVertexBuffer.h>
#include <GL/glew.h>

namespace Laser
{
	class VertexBuffer;
	class OpenGLVertexBuffer;
	namespace Command
	{
		class OpenGLVertexBuffer : public Command::VertexBuffer
		{
		public:
			OpenGLVertexBuffer( );
			virtual bool Create( Laser::VertexBuffer *pVertexBuffer, Topology topology );

		public:
			virtual void Draw( DrawStatus &Status );
			
		private:
			const Laser::OpenGLVertexBuffer *mVertexBuffer;
			GLenum mTopology;
		};
	}
}
