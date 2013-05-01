#pragma once

#include <Laser/CommandClear.h>
#include <GL/glew.h>

namespace Laser
{
	namespace Command
	{
		class OpenGLClear : public Command::Clear
		{
		public:
			OpenGLClear();

		public:
			void Draw( DrawStatus &Status );
			virtual void SetColor( float red, float greeb, float blue, float alpha );

		private:
			GLclampf mRed, mGreen, mBlue, mAlpha;
			
		};
	}
}