#include <Laser/Common/System/CommandFactory.h>
#include <Laser/Common/Command/IBase.h>
#include <TGUL/String.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/assign.hpp>
#include <map>

#include <Laser/OpenGL/Command/OpenGLClear.h>

namespace Laser
{
	namespace System
	{
		bool CreateClear( Command::IBase **ppBase )
		{
			*ppBase = new Command::OpenGLClear();

			if( *ppBase == 0 ) {
				return false;
			}

			return true;
		}

		bool CommandFactory::CreateCommand( const TGUL::String &name, Command::IBase **ppBase )
		{
			std::map< TGUL::String, boost::function< bool( Command::IBase **) > > functions = boost::assign::map_list_of(
				"Clear", boost::bind( &CreateClear, ppBase )
				);

			if( functions.find( name ) == functions.end() ) {
				return false;
			}

			if( functions[ name ]( ppBase ) == false ) {
				return false;
			}
			return true;
		}
	}
}
