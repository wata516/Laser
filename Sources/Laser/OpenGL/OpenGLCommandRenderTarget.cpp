#include "OpenGLCommandRenderTarget.h"
#include <Laser/RenderTarget.h>
#include "OpenGLRenderTarget.h"

namespace Laser
{
	namespace Command
	{
		bool OpenGLRenderTarget::Create( Laser::RenderTarget *pRenderTarget )
		{
			void *pRenderTargetTmp = 0;
			if( pRenderTarget->QueryInterface( UUIDS::OPENGL_RENDER_TARGET, &pRenderTargetTmp ) == false ) {
				return false;
			}
			mRenderTarget = static_cast< Laser::OpenGLRenderTarget * >( pRenderTargetTmp );

			return true;
		}

		void OpenGLRenderTarget::Draw( DrawStatus &Status )
		{
			if( mRenderTarget->IsAvailable() ) {
				glBindFramebuffer( GL_FRAMEBUFFER, mRenderTarget->GetHandle() );
			}
		}

		void OpenGLRenderTargetReset::Draw( DrawStatus &Status )
		{
			glBindFramebuffer( GL_FRAMEBUFFER, 0 );
		}
	}
}