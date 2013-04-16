#pragma once

#include <list>
#include <boost/shared_ptr.hpp>
#include <Laser/Common/User/ITechnique.h>

namespace Laser
{
	namespace User
	{
		class IPass;
	}
}


namespace Laser
{
	namespace User
	{
		class Technique : public ITechnique
		{
			typedef boost::shared_ptr< IPass > pass_ptr;
			typedef const pass_ptr pass_ptr_const;

		protected:
			std::list< pass_ptr_const > mPass;

		public:
			virtual void Render( ) const;
			bool Regist( const IPass &pass );
		};
	}
}