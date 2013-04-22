#pragma once

#include <Laser/ResourceManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	class OpenGLResourceManager : public ResourceManager
	{
	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}