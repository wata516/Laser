#include "OpenGLCommandShader.h"
#include <boost/foreach.hpp>
#include "Laser/OpenGLShader.h"

namespace Laser
{
	namespace Command
	{
		OpenGLShader::OpenGLShader()
		: mProgram( 0 )
		{
			BOOST_FOREACH( const Laser::Shader *value, mShaders ) {
				value = 0;
			}
		}

		void OpenGLShader::Draw()
		{
			bool Availables = false;
			BOOST_FOREACH( const Laser::Shader *pShader, mShaders ) {
				if( pShader && (pShader->IsAvailable() == false )) {
					Availables = false;
				}
			}

			if( Availables ) {
				BOOST_FOREACH( const Laser::Shader *pShader, mShaders ) {
					if( pShader ) {
						
					}
				}
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
			mProgram = glCreateProgram( );
			if( mProgram == 0 ) {
				return false;
			}
			
			BOOST_FOREACH( Laser::OpenGLShader *pShader, mShaders ) {
				glAttachShader( mProgram, pShader->GetShader() );
			}
			
			glLinkProgram( mProgram );
			
			return true;
		}

	}
}
