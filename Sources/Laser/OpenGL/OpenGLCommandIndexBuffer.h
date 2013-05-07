#pragma once

#include <Laser/CommandIndexBuffer.h>
#include <GL/glew.h>

namespace Laser
{
	class IndexBuffer;
	class OpenGLIndexBuffer;
	namespace Command
	{
		class OpenGLIndexBuffer : public Command::IndexBuffer
		{
		public:
			OpenGLIndexBuffer( );
			virtual bool Create( Laser::IndexBuffer *pIndexBuffer );

		public:
			virtual void Draw( DrawStatus &Status );

		private:
			const Laser::OpenGLIndexBuffer *mIndexBuffer;
		};
	}
}
