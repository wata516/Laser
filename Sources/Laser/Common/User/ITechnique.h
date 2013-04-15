#pragma once

namespace Laser
{
	namespace User
	{
		class ITechnique
		{
		public:
			virtual void Draw( ) = 0;
			virtual uint GetClassSize() const = 0;
		};
	}
}