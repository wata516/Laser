#pragma once

#include <vector>
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
			std::vector< pass_ptr_const > mPass;

		public:
			virtual void Render( ) const;
			template< typename T >
			bool Regist( const T &pass );
		};
		
		template< typename T >
		bool Technique::Regist( const T &pass )
		{
			T *pNewPass = new T;

			if( pNewPass == 0 ) {
				return false;
			}
			*pNewPass = pass;

			mPass.push_back( pNewPass );
			
			return true;
		}
	}
}