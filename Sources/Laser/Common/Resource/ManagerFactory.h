#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resource
	{
		class Manager;
	}
}

namespace Laser
{
	namespace Resource
	{
		class ManagerFactory
		{
		public:
			static bool Create( const TGUL::String &name, Manager **ppManager );
		};
	}
}
