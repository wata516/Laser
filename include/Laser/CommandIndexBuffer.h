#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class IndexBuffer;
	namespace Command
	{
		class IndexBuffer : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_INDEX_BUFFER > ID;

		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_INDEX_BUFFER;}
			virtual bool Create( Laser::IndexBuffer *pIndexBuffer ) = 0;
		};
	}
}