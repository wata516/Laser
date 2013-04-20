#pragma once

#include <Laser/Common/System/IUnknown.h>

namespace Laser
{
	namespace System
	{
		class Object : public IUnknown
		{
			unsigned int mReference;

		public:
			static const System::UUID &GetUUID( ) { return System::UUIDS::OBJECT; }
			
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
			virtual bool QueryInterface( const System::UUID &uuid, void **ppObject );
		};
		bool Object::QueryInterface( const System::UUID &uuid, void **ppObject )
		{
			if( uuid == GetUUID() || uuid == System::UUIDS::IUNKNOWN) {
				*ppObject = this;
				return true;
			}
		
			return false;
		}
	}
}