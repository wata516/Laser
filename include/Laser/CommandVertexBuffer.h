#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	namespace Command
	{
		class VertexBuffer : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_VERTEX_BUFFER > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_VERTEX_BUFFER;}
		};
	}
}