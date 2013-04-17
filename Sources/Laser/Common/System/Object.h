#pragma once

namespace Laser
{
	namespace System
	{
		class Object
		{
			int mReference;
			
		public:
			Object( )
				: mReference( 0 )
			{ }
			~Object( );
			
			void InclimentReference( ) {
				++ mReference;
			}
			
			bool DeclimentReference( ) {
				if( ( -- mReference ) == 0 ) {

					return true;
				}

				return false;
			}
			
			virtual void Destroy( ) { }
			
		};
	}
}