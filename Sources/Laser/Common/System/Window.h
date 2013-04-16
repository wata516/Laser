#pragma once

#include <Laser/common/System/IWindow.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class TechniqueManager;
	}
}

namespace Laser
{
	namespace System
	{
		class Window : public IWindow
		{
		public:
			Window();

		public:
			void Render( ) const;
			void SetTechnique(const Laser::System::TechniqueManager *pTechniqueManager);

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}