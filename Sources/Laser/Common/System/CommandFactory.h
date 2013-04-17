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
	namespace System
	{
		class CommandFactory
		{
		public:
			static bool CreateCommand( const TGUL::String &name, Command::IBase **ppBase );
		};
	}
}
