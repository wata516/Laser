#pragma once

#include <Laser/Common/System//TechniqueManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class OpenGLTechniqueManager : public ITechniqueManager
		{
		public:
			OpenGLTechniqueManager();

	//	private:
	//		class Impl;
	//		boost::shared_ptr< Impl > mImpl;
		};
	}
}
