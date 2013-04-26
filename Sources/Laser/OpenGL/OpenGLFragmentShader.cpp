#include "OpenGLFragmentShader.h"
#include <TGUL/String.h>
#include <boost/scoped_array.hpp>
#include <boost/numeric/conversion/converter.hpp>
#include <Laser/Exception.h>

namespace Laser
{
	bool OpenGLFragmentShader::Load( const TGUL::String &FileName, size_t ReadSize )
	{
		bool result = ReadASync( FileName, ReadSize );
		
		if( result == false ) {
			mStatus = STATUS_NONE;
			return false;
		}
		mStatus = STATUS_FILE_READING;
		
		return true;
	}

	bool OpenGLFragmentShader::ReadComplete( void *pBuffer, size_t BufferSize )
	{
		GLint BufferSizeGL;

		try {
			BufferSizeGL = boost::numeric::converter< GLint, size_t >::convert( BufferSize );
		} catch( std::exception const& ) {
			ASSERT( 0, "numeric cast exception." );
			return false;
		}
		
		const GLchar *pBufferGL = static_cast< GLchar * >( pBuffer );

		return CompileShader( GL_FRAGMENT_SHADER, pBufferGL, BufferSizeGL );
	}
	bool OpenGLFragmentShader::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN || uuid == UUIDS::OPENGL_FRAGMENT_SHADER ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}

}
