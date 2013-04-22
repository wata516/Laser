#include <Laser/ManagerFactory.h>
#include <Laser/GraphicsManager.h>
#include <Laser/OpenGL/OpenGLGraphicsManager.h>
#include <TGUL/String.h>
#include <TGUL/Map.h>

#include <boost/assign.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Laser
{
		bool CreateOpenGL( const TGUL::String &name, GraphicsManager **ppManager )
        {
            *ppManager = new OpenGLGraphicsManager( name );

            if( *ppManager == 0 ) {
                return false;
            }
            
            return true;
        }

        bool GraphicsManagerFactory::Create( const TGUL::String &name, GraphicsManager **ppManager )
        {
            std::map< TGUL::String, boost::function< bool( const TGUL::String &, GraphicsManager ** ) > > functions = boost::assign::map_list_of(
                "OpenGL", boost::bind( &CreateOpenGL, name, ppManager )   // OpenGL
            );
            
            *ppManager = 0;
            
            if( functions.find( name ) == functions.end() ) {
                return false;
            }

            if( functions[ name ]( name, ppManager ) == false ) {
                return false;
            }
			return true;
        }
}
