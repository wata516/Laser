#pragma once

namespace Laser
{
	namespace Command
	{
		class IBase
		{
		public:
			virtual void draw() = 0;
		};
	}
}