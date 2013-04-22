#pragma once

namespace Laser
{
	namespace User
	{
		class ITechnique
		{
		public:
			virtual void Render( ) const = 0;
			virtual unsigned int GetClassSize() const = 0;
		};
	}
}