#include <Laser/Common/System/ObjectManager.h>
#include <map>

namespace Laser
{
	namespace System
	{
		class ObjectManager::Impl
		{
			std::map< Object *, Object *> mObject;
			
		};
		
		ObjectManager::ObjectManager()
		: mImpl( new Impl )
		{ }
	}
}