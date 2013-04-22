#pragma once

#include <Laser/IVertexDeclare.h>

namespace Laser
{
	class VertexDeclare : public IVertexDeclare
	{

	public:
		explicit VertexDeclare( const VertexType &type );
		
	public:
		virtual size_t GetSize() const;
		virtual const VertexType &GetType( ) const { return mTypes; }

	private:
		VertexType mTypes;
	};
}
