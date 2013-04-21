#include <Laser/Common/Material/VertexDeclare.h>
#include <boost/array.hpp>

namespace Laser
{
	template< size_t size, size_t array >
	struct GetVertexSize{
		enum { value = size * array };
	};

	boost::array< size_t, IVertexDeclare::TYPE_MAX > gSize = {
		GetVertexSize< sizeof( float ), 4 >::value	// P32
	};

	VertexDeclare::VertexDeclare( const VertexType &type )
	: mTypes( type )
	{}

	size_t VertexDeclare::GetSize() const
	{
		size_t result = 0;

		for( size_t i = 0 ; i < IVertexDeclare::TYPE_MAX ; ++ i ) {
			if( mTypes[i] ) {
				result += gSize[i];
			}
		}

		return result;
	}
}