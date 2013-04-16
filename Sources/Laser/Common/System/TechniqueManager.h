#pragma once

#include <Laser/Common/System/ITechniqueManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace User
	{
		class ITechnique;
	}
}

namespace Laser
{
	namespace System
	{
		class TechniqueManager : public ITechniqueManager
		{
		public:
			TechniqueManager();

			bool Regist( const User::ITechnique &technique );
			void Render( ) const;
		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}
