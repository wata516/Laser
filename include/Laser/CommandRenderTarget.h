#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class RenderTarget;
	namespace Command
	{
		class RenderTarget : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_RENDER_TARGET > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_RENDER_TARGET;}
			
		public:
			virtual bool Create( Laser::RenderTarget *pRenderTarget ) = 0;

		};
		
		class RenderTargetReset : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_RENDER_TARGET_RESET > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_RENDER_TARGET_RESET;}
		};
	}
}