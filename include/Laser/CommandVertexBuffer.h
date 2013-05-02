#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class VertexBuffer;
	namespace Command
	{
		class VertexBuffer : public IBase
		{
		public:
			enum Topology {
				TOPOLOGY_POINTS,
				TOPOLOGY_LINE_STRIP,
				TOPOLOGY_LINE_LOOP,
				TOPOLOGY_LINES,
				TOPOLOGY_LINE_STRIP_ADJACENCY,
				TOPOLOGY_LINES_ADJACENCY,
				TOPOLOGY_TRIANGLE_STRIP,
				TOPOLOGY_TRIANGLE_FAN,
				TOPOLOGY_TRIANGLES,
				TOPOLOGY_TRIANGLE_STRIP_ADJACENCY,
				TOPOLOGY_TRIANGLES_ADJACENCY,
				TOPOLOGY_MAX
			};
		public:
			static IDType< CLASS_ID_COMMAND_VERTEX_BUFFER > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_VERTEX_BUFFER;}
			virtual bool Create( Laser::VertexBuffer *pVertexBuffer, Topology topology ) = 0;
		};
	}
}