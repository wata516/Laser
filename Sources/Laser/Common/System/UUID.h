#pragma once

#if LASER_IS_COMPILER(MSVC)
#pragma warning(push)
#pragma warning(disable:4996)
#endif

#include <boost/uuid/uuid.hpp>

namespace Laser
{
	namespace System
	{
		typedef boost::uuids::uuid UUID;

		struct UUIDS {
			static const UUID IUNKNOWN;
			static const UUID IBUFFER;
			static const UUID OBJECT;
			static const UUID SYSMEMBUFFER;
			static const UUID RESOURCE_IMANAGER;
			static const UUID RESOURCE_MANAGER;

		};
	}
}

#if LASER_IS_COMPILER(MSVC)
#pragma warning(pop)
#endif