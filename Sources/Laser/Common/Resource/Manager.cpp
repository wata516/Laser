#include <Laser/Common/Resource/Manager.h>
#include <Laser/Common/Resource/Buffer.h>
#include <Laser/Common/Resource/BufferFactory.h>
#include <TGUL/String.h>
#include <map>

namespace Laser
{
	namespace Resource
	{
		class Manager::Impl
		{
			std::map< Buffer *, boost::shared_ptr< Buffer > > mBuffers;
		};
		
		bool Manager::Create( const TGUL::String &name, Buffer **ppBuffer )
		{
			return BufferFactory::Create( name, ppBuffer );
		}
	}
}