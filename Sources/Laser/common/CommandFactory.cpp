#include <Laser/CommandFactory.h>
#include <Laser/IBase.h>
#include <TGUL/String.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/assign.hpp>
#include <map>

#include "../OpenGL/OpenGLCommandClear.h"
#include "../OpenGL/OpenGLCommandVertexBuffer.h"
#include "../OpenGL/OpenGLCommandMaterial.h"
#include "../OpenGL/OpenGLCommandRenderTarget.h"
#include "../OpenGL/OpenGLCommandViewport.h"

namespace Laser
{
	bool CreateClear( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLClear();

		if( *ppBase == 0 ) {
			return false;
		}

		return true;
	}

	bool CreateVertexBuffer( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLVertexBuffer();
		
		if( *ppBase == 0 ) {
			return false;
		}
		
		return true;
	}

	bool CreateMaterial( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLMaterial();
		
		if( *ppBase == 0 ) {
			return false;
		}
		
		return true;
	}

	bool CreateRenderTarget( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLRenderTarget();
		
		if( *ppBase == 0 ) {
			return false;
		}
		
		return true;
	}

	bool CreateRenderTargetReset( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLRenderTargetReset();
		
		if( *ppBase == 0 ) {
			return false;
		}
		
		return true;
	}

	bool CreateViewport( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLViewport();
		
		if( *ppBase == 0 ) {
			return false;
		}
		
		return true;
	}

	bool CommandFactory::CreateCommand( const TGUL::String &name, Command::IBase **ppBase )
	{
		std::map< TGUL::String, boost::function< bool( Command::IBase **) > > functions = boost::assign::map_list_of
			("Clear", boost::bind( &CreateClear, ppBase ))
			("VertexBuffer", boost::bind( &CreateVertexBuffer, ppBase ))
			("Material", boost::bind( &CreateMaterial, ppBase ))
			("RenderTarget", boost::bind( &CreateRenderTarget, ppBase ))
			("RenderTargetReset", boost::bind( &CreateRenderTargetReset, ppBase ))
			("Viewport", boost::bind( &CreateViewport, ppBase ))
		;

		if( functions.find( name ) == functions.end() ) {
			return false;
		}

		if( functions[ name ]( ppBase ) == false ) {
			return false;
		}
		return true;
	}
}
