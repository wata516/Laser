#include "OpenGLVertexShader.h"
#include <TGUL/String.h>
#include <boost/scoped_array.hpp>
#include <boost/numeric/conversion/converter.hpp>
#include <Laser/Exception.h>

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
		GLint BufferSizeGL;
		
		try {
			BufferSizeGL = boost::numeric::converter< GLint, size_t >::convert( BufferSize );
		} catch( std::exception const& ) {
			ASSERT( 0, "numeric cast exception." );
			return false;
		}
		
		const GLchar *pBufferGL = static_cast< GLchar * >( pBuffer );
		
		return CompileShader( GL_VERTEX_SHADER, pBufferGL, BufferSizeGL );
	}

	OpenGLVertexShader::OpenGLVertexShader()
		: mStatus( STATUS_NONE )
	{ }

	bool OpenGLVertexShader::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::IUNKNOWN || uuid == UUIDS::OPENGL_VERTEX_SHADER ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}
}