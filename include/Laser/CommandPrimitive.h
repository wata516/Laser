#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class IndexBuffer;
	class VertexBuffer;
	namespace Command
	{
		class Primitive : public IBase
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
			static IDType< CLASS_ID_COMMAND_PRIMITIVE > ID;

		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_PRIMITIVE;}
			virtual bool Create( Laser::IndexBuffer *pIndexBuffer, Laser::VertexBuffer *pVertexBuffer, Topology topology ) = 0;
			virtual void Draw( DrawStatus &Status ) = 0;

		};
	}
}
