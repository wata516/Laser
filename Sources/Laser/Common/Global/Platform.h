#pragma once

enum {
	COMPILER_MS_VISUAL_STUDIO,
	COMPILER_APPLE_XCODE
};

#if defined _MSC_VER
#define LASER_COMPILER COMPILER_MS_VISUAL_STUDIO
#endif

#define ISCOMPILER( COMPILER ) ( LASER_COMPILER == COMPILER_##COMPILER )

#if !defined(LASER_COMPILER)
#error not support compiler
#endif
