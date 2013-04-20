#pragma once

#include <Laser/Common/System/IManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class Manager : public IManager
		{
		public:
			Manager();
		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}