#pragma once

#include <vector>
#include <boost/shared_ptr.hpp>
#include <Laser/ITechnique.h>

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
			typedef boost::shared_ptr< const IPass > pass_ptr;

		protected:
			std::vector< pass_ptr > mPass;

		public:
			virtual void Render( ) const;
			template< typename T >
			bool Regist( const T &pass );
		};
		
		template< typename T >
		bool Technique::Regist( const T &pass )
		{
			const T *pNewPass = new T( pass );

			if( pNewPass == 0 ) {
				return false;
			}

			mPass.push_back( pass_ptr( pNewPass ) );
			
			return true;
		}
	}
}