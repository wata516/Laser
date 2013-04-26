#include <Laser/CommandFactory.h>
#include <Laser/IBase.h>
#include <TGUL/String.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/assign.hpp>
#include <map>

#include "../OpenGL/OpenGLCommandClear.h"
#include "../OpenGL/OpenGLCommandShader.h"

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

	bool CreateShader( Command::IBase **ppBase )
	{
		*ppBase = new Command::OpenGLShader();

		if( *ppBase == 0 ) {
			return false;
		}

		return true;
	}

	bool CommandFactory::CreateCommand( const TGUL::String &name, Command::IBase **ppBase )
	{
		std::map< TGUL::String, boost::function< bool( Command::IBase **) > > functions = boost::assign::map_list_of
			("Clear", boost::bind( &CreateClear, ppBase ))
			("Shader", boost::bind( &CreateShader, ppBase ))
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
