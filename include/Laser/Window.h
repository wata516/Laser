#pragma once

#include <Laser/IWindow.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	class TechniqueManager;
}

namespace Laser
{
	class Window : public IWindow
	{
	public:
		Window();

	public:
		void Render( ) const;
		void SetTechnique(const TechniqueManager *pTechniqueManager);

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}