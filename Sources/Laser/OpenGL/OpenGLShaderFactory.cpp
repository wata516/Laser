#include "OpenGLShaderFactory.h"

#include <Laser/IShader.h>
#include "OpenGLVertexShader.h"
#include "OpenGLFragmentShader.h"
#include <TGUL/String.h>

#include <boost/assign.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Laser
{
	bool CreateOpenGLVertexShader( const TGUL::String &name, IShader **ppShader )
	{
		*ppShader = new OpenGLVertexShader( );
		
		if( *ppShader == 0 ) {
			return false;
		}

		return true;
	}
	
	bool CreateOpenGLFragmentShader( const TGUL::String &name, IShader **ppShader )
	{
		*ppShader = new OpenGLFragmentShader( );
		
		if( *ppShader == 0 ) {
			return false;
		}

		return true;
	}

	bool OpenGLShaderFactory::Create( const TGUL::String &name, IShader **ppShader )
	{
		std::map< TGUL::String, boost::function< bool( const TGUL::String &, IShader ** ) > > functions
		= boost::assign::map_list_of
								( "VertexShader", boost::bind( &CreateOpenGLVertexShader, name, ppShader ))		// VertexShader
								("FragmentShader", boost::bind( &CreateOpenGLFragmentShader, name, ppShader ))	// FragmentShader
		;
		*ppShader = 0;
	
		if( functions.find( name ) == functions.end() ) {
			return false;
		}
	
		if( functions[ name ]( name, ppShader ) == false ) {
			return false;
		}
	
		return true;
	}
}