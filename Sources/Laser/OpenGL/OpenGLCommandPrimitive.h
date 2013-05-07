#pragma once

#include <Laser/CommandPrimitive.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLIndexBuffer;
	class OpenGLVertexBuffer;
	namespace Command
	{
		class OpenGLPrimitive : public Primitive
		{
		public:
			OpenGLPrimitive();

			virtual bool Create( Laser::IndexBuffer *pIndexBuffer, Laser::VertexBuffer *pVertexBuffer, Topology topology );
			virtual void Draw( DrawStatus &Status );

		private:
			const Laser::OpenGLIndexBuffer *mIndexBuffer;
			const Laser::OpenGLVertexBuffer *mVertexBuffer;
			GLenum mTopology;

		};
	}
}
