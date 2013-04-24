#include "OpenGLVertexShader.h"
#include <TGUL/String.h>

namespace Laser
{
	bool OpenGLVertexShader::Load( const TGUL::String &FileName, size_t ReadSize )
	{
		bool result = ReadASync( FileName, ReadSize );

		if( result == false ) {
			mStatus = STATUS_NONE;
			return false;
		}
		mStatus = STATUS_FILE_READING;

		return result;
	}

	bool OpenGLVertexShader::ReadComplete( void *pBuffer, size_t BufferSize )
	{
		return true;
	}

	OpenGLVertexShader::OpenGLVertexShader()
		: mStatus( STATUS_NONE )
	{ }
}