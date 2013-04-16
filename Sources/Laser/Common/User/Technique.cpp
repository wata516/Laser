
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

		bool Technique::Regist( const IPass &pass )
		{
			IPass *NewPass = reinterpret_cast< IPass * >( new uint8_t[ pass.GetClassSize() ] );

			memcpy( NewPass, &pass, pass.GetClassSize() );

			pass_ptr pBuff( NewPass );

			if( pBuff == 0 ) {
				return false;
			}

			*pBuff = pass;//.Clone();

			mPass.push_back( pBuff );

			return true;
		}
	}
}
