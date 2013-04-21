#include <Laser/Common/System/ObjectManager.h>
#include <map>

namespace Laser
{
		class ObjectManager::Impl
		{
			std::map< Object *, Object *> mObject;
			
		};
		
		ObjectManager::ObjectManager()
		: mImpl( new Impl )
		{ }
		void ObjectManager::Release( const Object &obj )
		{
			
		}
}