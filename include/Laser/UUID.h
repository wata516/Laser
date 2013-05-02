#pragma once

#if LASER_IS_COMPILER(MSVC)
#pragma warning(push)
#pragma warning(disable:4996)
#endif

#include <boost/uuid/uuid.hpp>

namespace Laser
{
	typedef boost::uuids::uuid UUID;

	struct UUIDS {
		static const UUID IUNKNOWN;
		static const UUID IBUFFER;
		static const UUID OBJECT;
		static const UUID VERTEX_BUFFER;
		static const UUID SHADER_UNIFORM_BUFFER;
		static const UUID TEXTURE_BUFFER;
		static const UUID RESOURCE_IMANAGER;
		static const UUID RESOURCE_MANAGER;
			
		static const UUID OPENGL_VERTEX_SHADER;
		static const UUID OPENGL_FRAGMENT_SHADER;
		static const UUID OPENGL_VERTEX_BUFFER;
		static const UUID OPENGL_SHADER_UNIFORM_BUFFER;
		static const UUID OPENGL_TEXTURE;
	};
}

#if LASER_IS_COMPILER(MSVC)
#pragma warning(pop)
#endif
