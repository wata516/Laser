#pragma once

#include <boost/shared_ptr.hpp>

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resource
	{
		class Buffer;
	}
};

namespace Laser
{
	namespace Resource
	{
		class BufferFactory
		{
		public:
			static bool Create( const TGUL::String &name, Buffer **ppBuffer );
		};
	}
}
