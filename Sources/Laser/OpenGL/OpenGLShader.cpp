#include "OpenGLShader.h"
#include <boost/scoped_array.hpp>
#include <TGUL/String.h>

namespace Laser
{
	OpenGLShader::OpenGLShader()
	: mIsAvailable( false )
	{}

	bool OpenGLShader::CompileShader( GLint ShaderType, const GLchar *pSourceCode, GLint SourceCodeSize )
	{
		mIsAvailable = false;

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

		mIsAvailable = true;

		return true;
	}
	
	bool OpenGLShader::IsAvailable() const
	{
		return mIsAvailable;
	}
	
	bool OpenGLShader::GetUniformIndex( const TGUL::String &Name, unsigned int *pIndex ) const
	{
		if( mIsAvailable == false ) {
			return false;
		}
		GLuint index = glGetUniformBlockIndex( mShader, Name.c_str() );
		if( index == GL_INVALID_INDEX ) {
			return false;
		}
		*pIndex = index;
		
		return true;
	}

}
