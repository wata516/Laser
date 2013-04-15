#pragma once

#include <Laser/Common/System/ITechniqueManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class TechniqueManager : public ITechniqueManager
		{
		public:
			TechniqueManager();

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}
