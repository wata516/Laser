
#include <Laser/Common/User/Technique.h>
#include <Laser/Common/User/Pass.h>
#include <boost/foreach.hpp>

namespace Laser
{
	namespace User
	{
		void Technique::Render() const
		{
			BOOST_FOREACH( pass_ptr_const pass, mPass ) {
				pass->Render();
			}
		}
	}
}
