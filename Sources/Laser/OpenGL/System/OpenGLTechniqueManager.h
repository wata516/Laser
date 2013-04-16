#pragma once

#include <Laser/Common/System//TechniqueManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class OpenGLTechniqueManager : public TechniqueManager
		{
		public:
			OpenGLTechniqueManager();

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}
