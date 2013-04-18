#include <Laser/Common/System/UUID.h>
#include <boost/uuid/uuid_generators.hpp>

namespace Laser
{
	namespace System
	{
		const UUID UUIDS::IUNKNOWN = boost::uuids::random_generator()();
		const UUID UUIDS::IBUFFER = boost::uuids::random_generator()();
		const UUID UUIDS::OBJECT = boost::uuids::random_generator()();
		const UUID UUIDS::SYSMEMBUFFER = boost::uuids::random_generator()();
	}
}
