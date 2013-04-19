#pragma once

#if ISCOMPILER(MS_VISUAL_STUDIO)
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

		};
	}
}

#if ISCOMPILER(MS_VISUAL_STUDIO)
#pragma warning(pop)
#endif
