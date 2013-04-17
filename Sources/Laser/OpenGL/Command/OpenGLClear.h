#pragma once

#include <Laser/Common/Command/Clear.h>
#include <GL/glfw.h>

namespace Laser
{
	namespace Command
	{
		class OpenGLClear : public Command::Clear
		{
		public:
			OpenGLClear();

		public:
			void Draw();
			virtual void SetColor( float red, float greeb, float blue, float alpha );

		private:
			GLclampf mRed, mGreen, mBlue, mAlpha;
			
		};
	}
}