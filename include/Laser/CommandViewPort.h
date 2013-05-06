#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	namespace Command
	{
		class Viewport : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_VIEWPORT > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_VIEWPORT;}
			virtual void SetViewport( int x, int y, unsigned int width, unsigned int height ) = 0;
		};
	}
}
