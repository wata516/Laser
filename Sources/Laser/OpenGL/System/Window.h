#pragma once

#include <Laser/Common/System/IWindow.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
    namespace System
    {
        class OpenGLWindow : public IWindow
        {
        public:
            virtual bool Create( int32_t x, int32_t y, int32_t width, int32_t height );

        private:
            class Impl;
            boost::shared_ptr< Impl > mImpl;
        };
    }
}