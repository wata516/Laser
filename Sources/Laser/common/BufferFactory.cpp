#include "BufferFactory.h"
#include <Laser/Buffer.h>
#include <Laser/SysmemBuffer.h>
#include <TGUL/String.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/assign.hpp>
#include <map>

namespace Laser
{
	namespace Resource
	{
		bool CreateSysmemBuffer( Buffer **ppBuffer )
		{
			*ppBuffer = new SysmemBuffer();

			if( *ppBuffer == 0 ) {
				return false;
			}

			return true;
		}

		bool BufferFactory::Create( const TGUL::String &name, Buffer **ppBuffer )
		{
			std::map< TGUL::String, boost::function< bool( Buffer **) > > functions = boost::assign::map_list_of(
				"SysmemBuffer", boost::bind( &CreateSysmemBuffer, ppBuffer )
				);

			*ppBuffer = 0;

			if( functions.find( name ) == functions.end() ) {
				return false;
			}

			if( functions[ name ]( ppBuffer ) == false ) {
				return false;
			}

			(*ppBuffer)->AddRef();

			return true;
		}
	}
}