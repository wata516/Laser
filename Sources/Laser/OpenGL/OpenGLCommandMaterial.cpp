#include "OpenGLCommandMaterial.h"
#include "OpenGLShaderUniformBuffer.h"
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
#include <Laser/DrawStatus.h>
#include <Laser/Shader.h>
#include <Laser/Texture.h>
#include <boost/foreach.hpp>

namespace Laser
{
	namespace Command
	{
		OpenGLMaterial::OpenGLMaterial()
		: mShaderUniformBuffer(0)
		{ }

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
				
				BOOST_FOREACH( TexturesType::value_type &texture, mTextures ) {
					uint32_t index = texture.first;
					OpenGLTexture *pTexture = texture.second;

					if( pTexture->IsAvailable() ) {
						GLuint SamplerUniformIndex = 0;
						if(	mShaderProgram.GetTextureIndex( pTexture->GetName(), &SamplerUniformIndex ) ) {
							pTexture->UpdateParameter( false );
							glActiveTexture( GL_TEXTURE0 + index );
							glBindTexture( GL_TEXTURE_2D, pTexture->GetHandle() );
							glUniform1i( SamplerUniformIndex, 0 );
						}
					}
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

		bool OpenGLMaterial::SetTexture( uint32_t index, const TGUL::String &name, Texture *pTexture )
		{
			TexturesType::iterator i = mTextures.find(index);
			bool find = ( i != mTextures.end() );

			if( pTexture == 0 ) {
				if( find ) {
					mTextures.erase(i);
				}

				return true;
			}

			void *pTextureBuf = 0;
			if( pTexture->QueryInterface( UUIDS::OPENGL_TEXTURE, &pTextureBuf ) == false ) {
				return false;
			}

			if( find == false ) {
				mTextures.insert( TexturesType::value_type( index, 0 ) );
			}

			mTextures[index] = static_cast< Laser::OpenGLTexture * >( pTextureBuf );
			mTextures[index]->SetName( name );
			
			return true;
		}

	}

}