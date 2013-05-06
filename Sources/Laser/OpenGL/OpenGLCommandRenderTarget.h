#pragma once

#include <Laser/CommandRenderTarget.h>
#include <GL/glew.h>

namespace Laser
{
	class RenderTarget;
	class OpenGLRenderTarget;
	namespace Command
	{
		class OpenGLRenderTarget : public Command::RenderTarget
		{
		public:
			virtual bool Create( Laser::RenderTarget *pRenderTarget );
			virtual void Draw( DrawStatus &Status );
			
		private:
			Laser::OpenGLRenderTarget *mRenderTarget;
		};
		
		class OpenGLRenderTargetReset : public RenderTargetReset
		{
		public:
			virtual void Draw( DrawStatus &Status );
		};
	}
}
