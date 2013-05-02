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
				
/*
				 Laser::OpenGLShader *pVertexShader;
				 
				 Laser::Shader *pVertexShaderTmp = Status.GetShader( Command::Shader::SHADER_TYPE_VERTEX );
				 void *pTmp;
				 if( pVertexShaderTmp->QueryInterface(Laser::OpenGLShader::GetUUID(), &pTmp ) ) {
				 pVertexShader = static_cast< Laser::OpenGLShader * >( pTmp );
				 
				 unsigned int TransformUniformIndex = 0;
				 //				if( pVertexShader->GetUniformIndex( mShaderUniformBuffer->GetName(), &TransformUniformIndex ) ) {
				 glUniformBlockBinding(pVertexShader->GetHandle(), TransformUniformIndex, 0);
				 glBindBufferBase( GL_UNIFORM_BUFFER, TransformUniformIndex, mShaderUniformBuffer->GetHandle() );
				 //				}
				 }*/
				
				GLuint UniformIndex = 0;
				if( mShaderProgram.GetUniformIndex( mShaderUniformBuffer->GetName(), &UniformIndex )) {
					glUniformBlockBinding(mShaderProgram.GetHandle(), UniformIndex, 0);
					glBindBufferBase( GL_UNIFORM_BUFFER, UniformIndex, mShaderUniformBuffer->GetHandle() );
				
					mShaderProgram.Draw();
				}

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