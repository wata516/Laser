
#pragma once

#include <Laser/Buffer.h>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class Shader : public Resource::Buffer
	{
	public:
		enum Status {
			STATUS_NONE,
			STATUS_FILE_READING,
			STATUS_AVAILABLE,
			STATUS_MAX
		};

	public:
		virtual bool Load( const TGUL::String &FileName, size_t ReadSize ) = 0;
		virtual bool IsAvailable() const = 0;
		
	};
}