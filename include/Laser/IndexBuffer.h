#pragma once

#include <Laser/Buffer.h>
#include <boost/function.hpp>

namespace Laser
{
	class IndexBuffer : public Resource::Buffer
	{
	public:
		enum IndexSize
		{
			INDEX_SIZE_U16,
			INDEX_SIZE_U32,
			INDEX_SIZE_MAX
		};
		typedef boost::function< size_t( void *pAddress, size_t a ) > WriteType;

		virtual bool Create( IndexSize type, unsigned int IndexNum ) = 0;
		virtual bool Write( WriteType WriteFunction ) = 0;


	};
}