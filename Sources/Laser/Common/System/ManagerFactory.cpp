#include "Laser/Common/System/ManagerFactory.h"
#include "Laser/Common/System/Manager.h"
#include "Laser/OpenGL/System/OpenGLManager.h"
#include <TGUL/String.h>
#include <TGUL/Map.h>

#include <boost/assign.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Laser
{
    namespace System
    {
         bool CreateOpenGL( Manager **ppManager )
        {
            *ppManager = new OpenGLManager( );

            if( *ppManager == 0 ) {
                return false;
            }
            
            return true;
        }

        bool ManagerFactory::Create( const TGUL::String &name, Manager **ppManager )
        {
            std::map< TGUL::String, boost::function< bool( Manager **) > > functions = boost::assign::map_list_of(
                "OpenGL", boost::bind( &CreateOpenGL, ppManager )   // OpenGL
            );
            
            *ppManager = 0;
            
            if( functions.find( name ) == functions.end() ) {
                return false;
            }

            if( functions[ name ]( ppManager ) == false ) {
                return false;
            }
			return true;
        }

    }
}
