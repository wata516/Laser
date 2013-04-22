#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Command
	{
		class IBase;
	}
}

namespace Laser
{
		class CommandFactory
		{
		public:
			static bool CreateCommand( const TGUL::String &name, Command::IBase **ppBase );
		};
}
