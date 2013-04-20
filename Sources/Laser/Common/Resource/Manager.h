#pragma once

#include <Laser/Common/Resource/IManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace Resource
	{
		class Buffer;
	}
}

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resource
	{
		class Manager : IManager
		{
		public:
			bool Create( const TGUL::String &name, Buffer **ppBuffer );

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
			
		};
	}
}
