#pragma once

#include <Laser/IUnknown.h>

namespace Laser
{
		class Object : public IUnknown
		{
			unsigned int mReference;

		public:
			static const UUID &GetUUID( ) { return UUIDS::OBJECT; }
			
		public:
			Object( )
				: mReference( 0 )
			{ }
			
			virtual ~Object() {}
			
			virtual unsigned int AddRef( ) {
				return ++ mReference;
			}
			
			virtual unsigned int Release( ) {
				if( ( -- mReference ) == 0 ) {
					delete this;
					return true;
				}

				return false;
			}
			virtual bool QueryInterface( const UUID &uuid, void **ppObject );
		};
}