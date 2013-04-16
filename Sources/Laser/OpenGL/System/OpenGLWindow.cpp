#include <Laser/OpenGL/System/OpenGLWindow.h>
#include <GL/glfw.h>

namespace Laser
{
    namespace System
    {
        class OpenGLWindow::Impl
        {
		public:
			Impl();

        public:
			bool Create( const TGUL::String &title, int x, int y, int width, int height );
			void Close( );
			bool Open( );
			bool IsOpen();
			void Flip();
		private:
			bool mIsOpen;
			TGUL::String mTitle;
			int mX, mY, mWidth, mHeight;
        };
        
        bool OpenGLWindow::Impl::Create( const TGUL::String &title, int x, int y, int width, int height )
        {
			mTitle = title;
			mX = x;
			mY = y;
			mWidth = width;
			mHeight = height;

            return true;
        }
		
		void OpenGLWindow::Impl::Close()
		{
			glfwCloseWindow();
			mIsOpen = false;
		}
		
		bool OpenGLWindow::Impl::Open()
		{
			if( glfwOpenWindow( mWidth, mHeight, 0, 0, 0, 0, 0, 0, GLFW_WINDOW ) == GL_FALSE ) {
				return false;
			}
			
			glfwSetWindowTitle( mTitle );
			
			glfwSwapInterval(1);
			
			mIsOpen = true;

			return true;
		}

		bool OpenGLWindow::Impl::IsOpen()
		{
			return mIsOpen;
		}
		
		void OpenGLWindow::Impl::Flip()
		{
			glfwSwapBuffers();
		}
        
		OpenGLWindow::Impl::Impl()
		: mIsOpen( false )
		, mX( 0 ), mY( 0 ), mWidth(0), mHeight(0)
		{
			
		}
		OpenGLWindow::OpenGLWindow()
		: mImpl( new Impl )
		{
		}
        bool OpenGLWindow::Create( const TGUL::String &title, int x, int y, int width, int height )
        {
            return mImpl->Create( title, x, y, width, height );
        }
		void OpenGLWindow::Close( )
		{
			mImpl->Close();
		}
		bool OpenGLWindow::Open( )
		{
			return mImpl->Open();
		}
		bool OpenGLWindow::IsOpen()
		{
			return mImpl->IsOpen();
		}
		void OpenGLWindow::Flip()
		{
			mImpl->Flip();
		}
    }
}