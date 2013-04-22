#pragma once

#include <Laser/ClassID.h>
#include <Laser/Exception.h>

namespace Laser
{
	namespace Command
	{
		class IBase
		{
		public:
			template < ClassID ID >
			struct IDType {
				enum { number = ID };
			};

		public:
			virtual ClassID GetClassID( ) const = 0;
			virtual void Draw() = 0;

			template< class T >
			T *Get( );
		};

		template< class T >
		T *IBase::Get( ) {
			if( this->GetClassID() == T::ID.number ) {
				return reinterpret_cast< T * >( this );
			}
		//	Laser::ASSERT( 0, "" );
			return 0;
		}
	}
}