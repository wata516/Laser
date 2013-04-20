#include <Laser/Common/Resource/ManagerFactory.h>
#include <Laser/Common/Resource/Manager.h>
#include <Laser/OpenGL/Resource/OpenGLManager.h>
#include <TGUL/String.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/assign.hpp>
#include <map>


namespace Laser
{
	namespace Resource
	{
		bool CreateOpenGL( Manager **ppManager )
		{
			*ppManager = new OpenGLManager();
			
			if( *ppManager == 0 ) {
				return false;
			}
			
			return true;
		}
		
		bool ManagerFactory::Create( const TGUL::String &name, Manager **ppManager )
		{
			std::map< TGUL::String, boost::function< bool( Manager **) > > functions =
			boost::assign::map_list_of(
									   "OpenGL", boost::bind( &CreateOpenGL, ppManager )
									   );
			
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
