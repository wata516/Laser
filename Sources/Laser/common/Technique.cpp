
#include <Laser/Technique.h>
#include <Laser/Pass.h>
#include <boost/foreach.hpp>

namespace Laser
{
	namespace User
	{
		void Technique::Render() const
		{
			BOOST_FOREACH( const pass_ptr pass, mPass ) {
				pass->Render();
			}
		}
	}
}
