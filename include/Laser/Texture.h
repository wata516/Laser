#pragma once

#include <Laser/Buffer.h>

namespace Laser
{
	class Texture : public Resource::Buffer
	{
		enum Status {
			STATUS_NONE,
			STATUS_FILE_READING,
			STATUS_AVAILABLE,
			STATUS_MAX
		};
	public:
		Texture();

	public:
		static const UUID &GetUUID( ) { return UUIDS::TEXTURE_BUFFER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );
		virtual bool IsAvailable() const = 0;
	
	private:
		Status mStatus;
	};
}
