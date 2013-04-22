#pragma once

namespace Laser
{
	namespace User
	{
		class IPass
		{
		public:
			virtual void Render() const = 0;
			virtual unsigned int GetClassSize() const = 0;
		};
	}
}
