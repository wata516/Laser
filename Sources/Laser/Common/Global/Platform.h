#pragma once

enum {
	PLATFORM_WIN32,
	PLATFORM_APPLE
};
enum {
	COMPILER_MSVC,
	COMPILER_APPLE_GCC
};

#if defined( __WIN32__ ) || defined( _WIN32 )
#define LASER_PLATFORM PLATFORM_WIN32
#elif defined( __APPLE_CC__)
#define LASER_PLATFORM PLATFORM_GNUC
#else
#error not support platform
#endif

#if defined _MSC_VER
#define LASER_COMPILER COMPILER_MS_VISUAL_STUDIO
#elif defined( __GNUC__)
#define LASER_COMPILER COMPILER_GNUC
#else
#eeror not support compiler
#endif

#define LASER_IS_COMPILER( COMPILER ) ( LASER_COMPILER == COMPILER_##COMPILER )
#define LASER_IS_PLATFORM( PLATFORM ) ( LASER_COMPILER == PLATFORM_##PLATFORM )

#include <stddef.h>
#include <Laser/Common/Global/Macros.h>