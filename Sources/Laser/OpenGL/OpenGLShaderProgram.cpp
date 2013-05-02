#include "OpenGLShaderProgram.h"
#include <boost/foreach.hpp>
#include "OpenGLShader.h"
#include <Laser/DrawStatus.h>
#include <boost/scoped_array.hpp>
#include <boost/tuple/tuple.hpp>

namespace Laser
{
	OpenGLShaderProgram::OpenGLShaderProgram()
	: mProgram( 0 )
	, mIsAvailable( false )
	{
		BOOST_FOREACH( const Laser::Shader *value, mShaders ) {
			value = 0;
		}
	}

	void OpenGLShaderProgram::Draw( )
	{
		if( mIsAvailable ) {
			glUseProgram( mProgram );
		}
	}
	
	bool OpenGLShaderProgram::CreateProgram( )
	{
		bool Availables = true;
		
		mIsAvailable = false;

		BOOST_FOREACH( const Laser::Shader *pShader, mShaders ) {
			if( pShader == 0 ) {
				Availables = false;
			} else if( pShader->IsAvailable() == false ) {
				Availables = false;
			}
		}
		
		if( Availables ) {
			if( mProgram == 0 ) {
				mProgram = glCreateProgram( );
				if( mProgram == 0 ) {
					return false;
				}
			}
			
			BOOST_FOREACH( Laser::OpenGLShader *pShader, mShaders ) {
				glAttachShader( mProgram, pShader->GetHandle() );
			}
			
			glLinkProgram( mProgram );
			
			GLint result;
			glGetProgramiv( mProgram, GL_LINK_STATUS, &result );
			if( result == GL_FALSE ) {
				int  nLogLength, nCharsWritten;
				glGetProgramiv( mProgram, GL_INFO_LOG_LENGTH, &nLogLength );
				
				boost::scoped_array< GLchar > pLogInfo( new GLchar[ nLogLength ] );
				
				glGetProgramInfoLog( mProgram, nLogLength, &nCharsWritten, pLogInfo.get() );
				
				printf("- glLinkProgram Error.¥n");
				printf("%s\n", pLogInfo.get() );
				
				return false;
			}
			
			mIsAvailable = true;
		}
		
		return true;
	}

	bool OpenGLShaderProgram::Create( Laser::Shader *pVertexShader, Laser::Shader *pFragmentShader )
	{
		BOOST_FOREACH( Laser::OpenGLShader *pShader, mShaders ) {
			pShader = 0;
		}
		typedef boost::tuple< UUID, ShaderType, Laser::Shader * > ShaderUUIDTuple;
		boost::array< ShaderUUIDTuple, SHADER_TYPE_MAX > uuids = {
			boost::make_tuple( UUIDS::OPENGL_VERTEX_SHADER, SHADER_TYPE_VERTEX, pVertexShader ),
			boost::make_tuple( UUIDS::OPENGL_FRAGMENT_SHADER, SHADER_TYPE_FRAGMENT, pFragmentShader )
		};
		
		BOOST_FOREACH( const ShaderUUIDTuple &ShaderTuple, uuids ) {
			const UUID &uuid = ShaderTuple.get<0>();
			const ShaderType &type = ShaderTuple.get<1>();
			Laser::Shader *pShader = ShaderTuple.get<2>();
			
			void *pGLShader = 0;
			if( pShader->QueryInterface( uuid, &pGLShader ) ) {
				mShaders[ type ] = static_cast< Laser::OpenGLShader * >( pGLShader );
			}
		}

		
		return mIsAvailable;
	}

	bool OpenGLShaderProgram::GetUniformIndex( const TGUL::String &Name, GLuint *pIndex ) const
	{
		if( mIsAvailable == false ) {
			return false;
		}
		GLuint index = glGetUniformBlockIndex( mProgram, Name.c_str() );
		if( index == GL_INVALID_INDEX ) {
			return false;
		}
		*pIndex = index;
		
		return true;
	}

	bool OpenGLShaderProgram::GetTextureIndex( const TGUL::String &Name, GLuint *pIndex ) const
	{
		if( mIsAvailable == false ) {
			return false;
		}
		GLuint index = glGetUniformLocation( mProgram, Name.c_str() );
		if( index == GL_INVALID_INDEX ) {
			return false;
		}
		*pIndex = index;
		
		return true;
	}
	
	bool OpenGLShaderProgram::IsAvailable() const
	{
		return mIsAvailable;
	}
}
