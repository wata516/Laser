#pragma once

#include <Laser/Common/System/IManager.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace Laser
{
	namespace System
	{
		class IWindow;
	}
	namespace Input
	{
		class IKeyboard;
	}
}

namespace Laser
{
    namespace System
    {
        class OpenGLManager : public IManager, boost::noncopyable
        {
        public:
            OpenGLManager();
            
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
}