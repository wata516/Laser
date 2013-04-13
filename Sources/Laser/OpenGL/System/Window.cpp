#include <Laser/OpenGL/System/Window.h>


namespace Laser
{
    namespace System
    {
        class OpenGLWindow::Impl
        {
        public:
            bool Create( int32_t x, int32_t y, int32_t width, int32_t height );
        };
        
        bool OpenGLWindow::Impl::Create( int32_t x, int32_t y, int32_t width, int32_t height )
        {
            
            return true;
        }
        
        bool OpenGLWindow::Create( int32_t x, int32_t y, int32_t width, int32_t height )
        {
            return mImpl->Create( x, y, width, height );
        }
    }
}