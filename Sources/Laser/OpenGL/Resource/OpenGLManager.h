#pragma once

#include <Laser/Common/Resource/Manager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace Resource
	{
		class OpenGLManager : public Resource::Manager
		{
		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}