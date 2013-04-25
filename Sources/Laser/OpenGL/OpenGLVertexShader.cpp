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
		mShader = glCreateShader( GL_VERTEX_SHADER );

		GLint BufferSizeGL;
		try {
			BufferSizeGL = boost::numeric::converter< GLint, size_t >::convert( BufferSize );
		} catch( boost::numeric::positive_overflow const& ) {
			ASSERT( 0, "" );
			return false;
		}

		const GLchar *pa = static_cast< GLchar * >( pBuffer );

		glShaderSource( mShader, sizeof( char ), &pa, &BufferSizeGL );
		glCompileShader( mShader );

		GLint compiled;
		glGetShaderiv( mShader, GL_COMPILE_STATUS, &compiled);

		if ( compiled == GL_FALSE ) {
			int  nLogLength, nCharsWritten;
			glGetShaderiv( mShader, GL_INFO_LOG_LENGTH, &nLogLength ); 

			// ÉGÉâÅ[ÉçÉOÇéÊìæ
			boost::scoped_array< GLchar > pLogInfo( new GLchar[ nLogLength ] );  

			glGetShaderInfoLog( mShader, nLogLength, &nCharsWritten, pLogInfo.get() );

			printf("%s\n", pLogInfo.get() );

			return false;
		}

		return true;
	}

	OpenGLVertexShader::OpenGLVertexShader()
		: mStatus( STATUS_NONE )
	{ }
}