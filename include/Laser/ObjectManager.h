#pragma once

#include <boost/shared_ptr.hpp>

namespace Laser
{
		class Object;

		class ObjectManager
		{
		public:
			ObjectManager( );
			
			void Release( const Object &obj );

			static ObjectManager &GetInstance( ) { static ObjectManager a; return a; }
		private:
			class Impl;
			boost::shared_ptr<Impl> mImpl;
		};
}