#include "OpenGLCommandMaterial.h"
#include "OpenGLShaderUniformBuffer.h"
#include "OpenGLShader.h"
#include <Laser/DrawStatus.h>
#include <Laser/Shader.h>
#include <boost/foreach.hpp>

namespace Laser
{
	namespace Command
	{
		void OpenGLMaterial::UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name )
		{
			mShaderUniformBuffer->Update( base );
			mShaderUniformBuffer->Bind( location, name );
		}

		void OpenGLMaterial::Draw( DrawStatus &Status )
		{
			if( mShaderProgram.IsAvailable() == false ) {
				mShaderProgram.CreateProgram();
			}

			if( IsAvailable() ) {

				GLuint UniformIndex = 0;
				if( mShaderProgram.GetUniformIndex( mShaderUniformBuffer->GetName(), &UniformIndex )) {
					glUniformBlockBinding(mShaderProgram.GetHandle(), UniformIndex, 0);
					glBindBufferBase( GL_UNIFORM_BUFFER, UniformIndex, mShaderUniformBuffer->GetHandle() );
				
				}
				mShaderProgram.Draw();

			}
			
		}

	
		bool OpenGLMaterial::Create( Laser::Shader *pVertexShader, Laser::Shader *pFragmentShader, ShaderUniformBuffer *pUniformBuffer )
		{
			void *pUniBuf = 0;
			if( pUniformBuffer->QueryInterface( UUIDS::OPENGL_SHADER_UNIFORM_BUFFER, &pUniBuf ) == false ) {
				return false;
			}
			mShaderUniformBuffer = static_cast< Laser::OpenGLShaderUniformBuffer * >( pUniBuf );

			if( mShaderProgram.Create(pVertexShader, pFragmentShader ) == false ) {
				return false;
			}

			return true;
		}
		
		bool OpenGLMaterial::IsAvailable() const
		{
			return mShaderProgram.IsAvailable();
		}
	}

}