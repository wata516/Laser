#pragma once

#include <Laser/Common/System/GraphicsManager.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace Laser
{
	class Window;
	namespace Input
	{
		class IKeyboard;
	}
}

namespace Laser
{
	class OpenGLGraphicsManager : public GraphicsManager, boost::noncopyable
	{
	public:
		OpenGLGraphicsManager( const TGUL::String &name );
            
		virtual bool Create( );
            
		virtual void Destroy( );

		virtual bool CreateWindow( Window **ppWindow );

		virtual bool CreateTechniqueManager( TechniqueManager **ppTechniqueManager );

		virtual bool CreateKeyboard( Input::IKeyboard **ppKeyboard );

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}