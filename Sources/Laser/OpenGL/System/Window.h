#pragma once

#include <Laser/Common/System/IWindow.h>
#include <TGUL/String.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
    namespace System
    {
        class OpenGLWindow : public IWindow
        {
		public:
			OpenGLWindow( );

        public:
			virtual bool Create( const TGUL::String &title, int x, int y, int width, int height );
			virtual void Close( );
			virtual bool Open( );
			virtual bool IsOpen( );

        private:
            class Impl;
            boost::shared_ptr< Impl > mImpl;
        };
    }
}