#pragma once

#include <Laser/Buffer.h>
#include <bitset>

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
		enum MinFilter {
			MIN_FILTER_NEAREST,
			MIN_FILTER_LINEAR,
			MIN_FILTER_NEAREST_MIPMAP_NEAREST,
			MIN_FILTER_LINEAR_MIPMAP_NEAREST,
			MIN_FILTER_NEAREST_MIPMAP_LINEAR,
			MIN_FILTER_LINEAR_MIPMAP_LINEAR,
			MIN_FILTER_MAX
		};

		enum MagFilter {
			MAG_FILTER_NEAREST,
			MAG_FILTER_LINEAR,
			MAG_FILTER_MAX
		};

		enum Wrap {
			WRAP_CLAMP_TO_EDGE,
			WRAP_CLAMP_TO_BORDER,
			WRAP_MIRRORED_REPEAT,
			WRAP_REPREAT,
			WRAP_MAX
		};
		
	protected:
		enum Update{
			UPDATE_MIN_FILTER,
			UPDATE_MAG_FILTER,
			UPDATE_WRAP,
			UPDATE_MAX
		};
		std::bitset< UPDATE_MAX > mUpdate;

	public:
		Texture();

	public:
		static const UUID &GetUUID( ) { return UUIDS::TEXTURE_BUFFER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize );
		virtual bool IsAvailable() const = 0;
		
	public:
		void SetMinFilter( MinFilter Filter );
		void SetMagFilter( MagFilter Filter );
		void SetWrap( Wrap s, Wrap t, Wrap r );
	
	private:
		Status mStatus;

	protected:
		MinFilter mMinFilter;
		MagFilter mMagFilter;
		Wrap mWrapS;
		Wrap mWrapT;
		Wrap mWrapR;
	};
}
