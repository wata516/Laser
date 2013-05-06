#include "OpenGLCommandViewport.h"

namespace Laser
{
	namespace Command
	{
		OpenGLViewport::OpenGLViewport()
		: mX(0)
		, mY(0)
		, mWidth( 0 )
		, mHeight( 0 )
		{ }

		void OpenGLViewport::Draw( DrawStatus &Status )
		{
			glViewport( mX, mY, mWidth, mHeight );
		}

		void OpenGLViewport::SetViewport( int x, int y, unsigned int width, unsigned int height )
		{
			mX = x;
			mY = y;
			mWidth = width;
			mHeight = height;
		}
		
	}
}
