#pragma once

#include <Laser/CommandViewport.h>
#include <GL/glew.h>

namespace Laser
{
	namespace Command
	{
		class OpenGLViewport : public Viewport
		{
		public:
			OpenGLViewport();

		public:
			virtual void Draw( DrawStatus &Status );
			virtual void SetViewport( int x, int y, unsigned int width, unsigned int height );

		private:
			GLint mX, mY;
			GLsizei mWidth, mHeight;
		};
	}
}