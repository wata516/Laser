#include "OpenGLShader.h"
#include <boost/scoped_array.hpp>

namespace Laser
{
	bool OpenGLShader::CompileShader( GLint ShaderType, const GLchar *pSourceCode, GLint SourceCodeSize )
	{
		mShader = glCreateShader( ShaderType );

		glShaderSource( mShader, 1, &pSourceCode, &SourceCodeSize );
		glCompileShader( mShader );
		
		GLint compiled;
		glGetShaderiv( mShader, GL_COMPILE_STATUS, &compiled);
		
		if ( compiled == GL_FALSE ) {
			int  nLogLength, nCharsWritten;
			glGetShaderiv( mShader, GL_INFO_LOG_LENGTH, &nLogLength );
			
			boost::scoped_array< GLchar > pLogInfo( new GLchar[ nLogLength ] );
			
			glGetShaderInfoLog( mShader, nLogLength, &nCharsWritten, pLogInfo.get() );
			
			printf("- Source Code");
			printf("%s", pSourceCode );
			printf("%s\n", pLogInfo.get() );
			
			return false;
		}

		return true;
	}
}
