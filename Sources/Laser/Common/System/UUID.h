#pragma once

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

		};
	}
}
