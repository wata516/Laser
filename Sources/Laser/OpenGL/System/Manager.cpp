#include <Laser/OpenGL/System/Manager.h>
#include <Laser/Common/System/IWindow.h>
#include <Laser/OpenGL/System/Window.h>
#include <GL/glfw.h>

namespace Laser
{
	namespace System
	{
		class OpenGLManager::Impl
		{
		public:
			bool Create();
			void Destroy();
			bool CreateWindow( IWindow **ppWindow );
		};
		
		bool OpenGLManager::Impl::Create( )
		{
			if( glfwInit() == GL_FALSE ) {
				return false;
			}

			glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
			glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
			glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			return true;
		}
		
		void OpenGLManager::Impl::Destroy( )
		{
			glfwTerminate();
		}

		bool OpenGLManager::Impl::CreateWindow( IWindow **ppWindow )
		{
			*ppWindow = new OpenGLWindow( );
			
			if( *ppWindow == 0 ) {
				return false;
			}
			
			return true;
		}

		OpenGLManager::OpenGLManager( )
		: mImpl( new Impl() )
		{
		}

		bool OpenGLManager::Create( )
		{
			return mImpl->Create();
		}
		void OpenGLManager::Destroy( )
		{
			mImpl->Destroy();
		}
		bool OpenGLManager::CreateWindow( IWindow **ppWindow )
		{
			return mImpl->CreateWindow( ppWindow );
		}
	}
}