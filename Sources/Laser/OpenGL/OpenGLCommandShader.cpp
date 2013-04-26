#include "OpenGLCommandShader.h"
#include <boost/foreach.hpp>

namespace Laser
{
	namespace Command
	{
		OpenGLShader::OpenGLShader()
		{
			BOOST_FOREACH( const Laser::Shader *value, mShaders ) {
				value = 0;
			}
		}

		void OpenGLShader::Draw()
		{
			bool Availables = false;
			BOOST_FOREACH( const Laser::Shader *pShader, mShaders ) {
				if( (pShader && pShader->IsAvailable()) == false ) {
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

		void OpenGLShader::SetShader( ShaderType type, const Laser::Shader *pShader )
		{
			pShader->GetUUID();
			mShaders[ type ] = pShader;
		}

	}
}
