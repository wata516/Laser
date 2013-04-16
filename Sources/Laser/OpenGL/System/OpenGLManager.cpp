#include <Laser/OpenGL/System/OpenGLManager.h>
#include <Laser/Common/System/IWindow.h>
#include <Laser/OpenGL/System/OpenGLWindow.h>
#include <Laser/Common/Input/IKeyboard.h>
#include <Laser/OpenGL/Input/OpenGLKeyboard.h>
#include <Laser/Common/System/ITechniqueManager.h>
#include <Laser/OpenGL/System/OpenGLTechniqueManager.h>
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
			bool CreateWindow( Window **ppWindow );
			bool CreateTechniqueManager( TechniqueManager **ppTechniqueManager );
			bool CreateKeyboard( Input::IKeyboard **ppKeyboard );
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

		bool OpenGLManager::Impl::CreateWindow( Window **ppWindow )
		{
			*ppWindow = new OpenGLWindow( );
			
			if( *ppWindow == 0 ) {
				return false;
			}
			
			return true;
		}

		bool OpenGLManager::Impl::CreateTechniqueManager( TechniqueManager **ppTechniqueManager )
		{
			*ppTechniqueManager = new OpenGLTechniqueManager( );

			if( *ppTechniqueManager == 0 ) {
				return false;
			}

			return true;
		}

		bool OpenGLManager::Impl::CreateKeyboard( Input::IKeyboard **ppKeyboard )
		{
			*ppKeyboard = new Input::OpenGLKeyboard( );

			if( *ppKeyboard == 0 ) {
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
		bool OpenGLManager::CreateWindow( Window **ppWindow )
		{
			return mImpl->CreateWindow( ppWindow );
		}
		bool OpenGLManager::CreateTechniqueManager( TechniqueManager **ppTechniqueManager )
		{
			return mImpl->CreateTechniqueManager( ppTechniqueManager );
		}

		bool OpenGLManager::CreateKeyboard( Input::IKeyboard **ppKeyboard )
		{
			return mImpl->CreateKeyboard( ppKeyboard );
		}
	}
}