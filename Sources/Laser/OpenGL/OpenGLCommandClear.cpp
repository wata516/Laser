#include "OpenGLCommandClear.h"

namespace Laser
{
	namespace Command
	{
		OpenGLClear::OpenGLClear()
		: mRed( 0.0F ), mGreen( 0.0F ), mBlue( 0.0F ), mAlpha( 1.0F )
		{ }
		
		void OpenGLClear::Draw( DrawStatus &Status )
		{
			glClearColor(mRed, mGreen, mBlue, mAlpha );
			glClear( GL_COLOR_BUFFER_BIT );
		}
		
		void OpenGLClear::SetColor( float red, float green, float blue, float alpha )
		{
			mRed = red; mGreen = green; mBlue = blue; mAlpha = alpha;
		}

	}
}