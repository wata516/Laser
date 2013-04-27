#include <Laser/VertexDeclare.h>
#include <boost/array.hpp>

namespace Laser
{
	template< size_t size, size_t array >
	struct GetVertexSize{
		enum { value = size * array };
	};

	boost::array< size_t, IVertexDeclare::TYPE_MAX > gSize = {
		GetVertexSize< sizeof( float ), 4 >::value,	// P32
		GetVertexSize< sizeof( float ), 4 >::value	// C32
	};

	size_t VertexDeclare::GetSize( ) const
	{
		size_t result = 0;

		for( size_t i = 0 ; i < IVertexDeclare::TYPE_MAX ; ++ i ) {
			if( mTypes[i] ) {
				result += gSize[i];
			}
		}

		return result;
	}

	void VertexDeclare::CreateVertexElement( IVertexDeclare::TYPE type, const TGUL::String &VariableName, int Locate )
	{
		mTypes[type] = 1;
		mVertexElements[ type ].VariableName = VariableName;
		mVertexElements[ type ].Locate = Locate;
	}
	
	size_t VertexDeclare::GetElementNum( ) const
	{
		return mTypes.count();
	}

	bool VertexDeclare::GetVertexType( size_t ElementIndex, IVertexDeclare::TYPE *pType ) const
	{
		size_t current = 0;
		for( size_t i = 0 ; i < IVertexDeclare::TYPE_MAX ; ++ i ) {
			if( mTypes[ i ] ) {
				if( current == ElementIndex ) {
					*pType = static_cast< IVertexDeclare::TYPE >( i );
					return true;
				}

				++ current;
			}
		}
		
		return false;
	}
	size_t VertexDeclare::GetTypeVertexSize( const IVertexDeclare::TYPE &type ) const
	{
		return gSize[type];
	}
	
	const VertexDeclare::VertexElement *VertexDeclare::GetElement( size_t ElementIndex ) const
	{
		IVertexDeclare::TYPE type;
		if( GetVertexType( ElementIndex, &type ) ) {
			return &mVertexElements[type];
		}
		
		return 0;
	}

}