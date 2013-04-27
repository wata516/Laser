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
			virtual bool Create( Laser::VertexBuffer *pVertexBuffer );

		public:
			void Draw();
			
		private:
			const Laser::OpenGLVertexBuffer *mVertexBuffer;
		};
	}
}
