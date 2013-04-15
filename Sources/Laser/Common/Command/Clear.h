#pragma once

#include <Laser/Common/Command/IBase.h>

namespace Laser
{
	namespace Command
	{
		class Clear : public IBase
		{
		public:
			virtual void SetColor( float red, float green, float blue, float alpha ) = 0;
		};
	}
}