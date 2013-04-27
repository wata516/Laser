#include "OpenGLCommandShader.h"
#include <boost/foreach.hpp>
#include "Laser/OpenGLShader.h"
#include <boost/scoped_array.hpp>

namespace Laser
{
	namespace Command
	{
		OpenGLShader::OpenGLShader()
		: mProgram( 0 )
		, mIsAvailable( false )
		{
			BOOST_FOREACH( const Laser::Shader *value, mShaders ) {
				value = 0;
			}
		}

		void OpenGLShader::Draw()
		{
			if( mIsAvailable ) {
				glUseProgram( mProgram );
			}
		}

		void OpenGLShader::SetShader( ShaderType type, Laser::Shader *pShader )
		{
			boost::array< UUID, Command::Shader::SHADER_TYPE_MAX > uuids = {
				UUIDS::OPENGL_VERTEX_SHADER,
				UUIDS::OPENGL_FRAGMENT_SHADER
			};

			void *pGLShader = 0;
			if( pShader->QueryInterface( uuids[type], &pGLShader ) ) {
				mShaders[ type ] = static_cast< Laser::OpenGLShader * >( pGLShader );
			}
		}

		bool OpenGLShader::Create()
		{
			bool Availables = true;
			
			mIsAvailable = false;

			BOOST_FOREACH( const Laser::Shader *pShader, mShaders ) {
				if( pShader && (pShader->IsAvailable() == false )) {
					Availables = false;
				}
			}
			
			if( Availables ) {
				mProgram = glCreateProgram( );
				if( mProgram == 0 ) {
					return false;
				}
			
				BOOST_FOREACH( Laser::OpenGLShader *pShader, mShaders ) {
					glAttachShader( mProgram, pShader->GetShader() );
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
			
			return mIsAvailable;
		}
		
		bool OpenGLShader::IsAvailable() const
		{
			return mIsAvailable;
		}

	}
}
