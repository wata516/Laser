#pragma once

#include <Laser/Common/Command/IBase.h>

namespace Laser
{
	namespace Command
	{
		class Clear : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_CLEAR > ID;

		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_CLEAR;}
			virtual void SetColor( float red, float green, float blue, float alpha ) = 0;
		};
	}
}