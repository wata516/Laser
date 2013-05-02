#pragma once

#include <Laser/Buffer.h>
#include <Laser/VertexDeclare.h>
#include <Laser/UUID.h>
#include <boost/shared_array.hpp>

namespace Laser
{
	class VertexBuffer : public Resource::Buffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

	public:
		static const UUID &GetUUID( ) { return UUIDS::VERTEX_BUFFER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Read( const TGUL::String &FileName ) { return false; }
		virtual bool Create( const VertexDeclare &declare, size_t VertexNum );
		virtual bool Write( WriteType WriteFunction );
		size_t GetVertexNum( ) const { return mVertexNum; }

	protected:
		VertexDeclare mDeclare;
		size_t mVertexNum;
	};
}
