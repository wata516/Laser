#include "OpenGLGraphicsManager.h"
#include "OpenGLWindow.h"
#include "OpenGLKeyboard.h"
#include "OpenGLTechniqueManager.h"
#include "OpenGLResourceManager.h"
#include <Laser/IWindow.h>
#include <Laser/IKeyboard.h>
#include <Laser/ITechniqueManager.h>
#include <Laser/ResourceManager.h>
#define GLFW_NO_GLU
#include <GL/glew.h>
#include <GL/glfw.h>

namespace Laser
{
	class OpenGLGraphicsManager::Impl
	{
			
	public:
		bool Create( const TGUL::String &name );
		void Destroy();
		bool CreateWindow( Window **ppWindow );
		bool CreateTechniqueManager( TechniqueManager **ppTechniqueManager );
		bool CreateResourceManager( ResourceManager **ppResourceManager );
		bool CreateKeyboard( Input::IKeyboard **ppKeyboard );
	};
		
	bool OpenGLGraphicsManager::Impl::Create( const TGUL::String &name )
	{
		glewExperimental = GL_TRUE;
		if( glfwInit() == GL_FALSE ) {
			return false;
		}
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
		glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
		glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return true;
	}
		
	void OpenGLGraphicsManager::Impl::Destroy( )
	{
		glfwTerminate();
	}

	bool OpenGLGraphicsManager::Impl::CreateWindow( Window **ppWindow )
	{
		*ppWindow = new OpenGLWindow( );
			
		if( *ppWindow == 0 ) {
			return false;
		}
			
		return true;
	}

	bool OpenGLGraphicsManager::Impl::CreateTechniqueManager( TechniqueManager **ppTechniqueManager )
	{
		*ppTechniqueManager = new OpenGLTechniqueManager( );

		if( *ppTechniqueManager == 0 ) {
			return false;
		}

		return true;
	}
		
	bool OpenGLGraphicsManager::Impl::CreateResourceManager( ResourceManager **ppResourceManager )
	{
		*ppResourceManager = new OpenGLResourceManager( );
		
		if( *ppResourceManager == 0 ) {
			return false;
		}
			
		return true;
	}
		
	bool OpenGLGraphicsManager::Impl::CreateKeyboard( Input::IKeyboard **ppKeyboard )
	{
		*ppKeyboard = new Input::OpenGLKeyboard( );

		if( *ppKeyboard == 0 ) {
			return false;
		}

		return true;
	}

	OpenGLGraphicsManager::OpenGLGraphicsManager( const TGUL::String &name )
		: mImpl( new Impl( ) )
		, GraphicsManager( name )
	{}

	bool OpenGLGraphicsManager::Create( )
	{
		if( mImpl->Create( GetFactoryName() ) == false ) {
			return false;
		}
		if( mImpl->CreateResourceManager(&mResourceManager) == false ) {
			return false;
		}
			
		return true;
	}
	
	void OpenGLGraphicsManager::Destroy( )
	{
		mImpl->Destroy();
	}
	
	bool OpenGLGraphicsManager::CreateWindow( Window **ppWindow )
	{
		return mImpl->CreateWindow( ppWindow );
	}
	
	bool OpenGLGraphicsManager::CreateTechniqueManager( TechniqueManager **ppTechniqueManager )
	{
		return mImpl->CreateTechniqueManager( ppTechniqueManager );
	}

	bool OpenGLGraphicsManager::CreateKeyboard( Input::IKeyboard **ppKeyboard )
	{
		return mImpl->CreateKeyboard( ppKeyboard );
	}
}
