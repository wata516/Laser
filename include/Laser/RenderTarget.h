#pragma once

#include <Laser/Buffer.h>

namespace Laser
{
	class RenderTarget : public Resource::Buffer
	{
	public:
		RenderTarget() {}

	public:
		static const UUID &GetUUID( ) { return UUIDS::RENDER_TARGET; }
//		virtual bool QueryInterface( const UUID &uuid, void **ppObject ) = 0;

	public:
		virtual bool Create( unsigned int width, unsigned int height ) = 0;
	};
}
