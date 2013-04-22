#include <Laser/UUID.h>
#include <boost/uuid/uuid_generators.hpp>

namespace Laser
{
		const UUID UUIDS::IUNKNOWN = boost::uuids::random_generator()();
		const UUID UUIDS::IBUFFER = boost::uuids::random_generator()();
		const UUID UUIDS::OBJECT = boost::uuids::random_generator()();
		const UUID UUIDS::SYSMEMBUFFER = boost::uuids::random_generator()();
		const UUID UUIDS::RESOURCE_IMANAGER = boost::uuids::random_generator()();
		const UUID UUIDS::RESOURCE_MANAGER = boost::uuids::random_generator()();
}
