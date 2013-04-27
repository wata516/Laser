#pragma once

#include <Laser/IVertexDeclare.h>
#include <TGUL/String.h>
#include <boost/array.hpp>

namespace Laser
{
	class VertexDeclare : public IVertexDeclare
	{
	public:
		struct VertexElement
		{
			TGUL::String VariableName;
			int Locate;
		};
		typedef boost::array< VertexElement, IVertexDeclare::TYPE_MAX > ElementsType;

	public:
		VertexDeclare() {}
		~VertexDeclare() {}
		
	public:
		void CreateVertexElement( IVertexDeclare::TYPE type, const TGUL::String &VariableName, int Locate );
		virtual size_t GetSize() const;
		virtual size_t GetElementNum( ) const;
		bool GetVertexType( size_t ElementIndex, IVertexDeclare::TYPE *pType ) const;
		size_t GetTypeVertexSize( const IVertexDeclare::TYPE &type ) const;
		
		virtual const VertexType &GetType( ) const { return mTypes; }
		const VertexElement *GetElement( size_t ElementIndex ) const;

	private:
		VertexType mTypes;
		ElementsType mVertexElements;
	};
}
