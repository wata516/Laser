#include "Laser/Common/System/ManagerFactory.h"
#include "Laser/Common/System/IManager.h"
#include "Laser/OpenGL/System/Manager.h"
#include <TGUL/String.h>
#include <TGUL/Map.h>

#include <boost/assign.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Laser
{
    namespace System
    {
         bool CreateOpenGL( IManager **ppManager )
        {
            *ppManager = new OpenGLManager( );

            if( *ppManager == 0 ) {
                return false;
            }
            
            return true;
        }
        
        bool ManagerFactory::Create( const TGUL::String &name, IManager **ppManager )
        {
            std::map< TGUL::String, boost::function< bool( IManager **) > > functions = boost::assign::map_list_of(
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
        };
    }
}
