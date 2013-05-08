#include "OpenGLCommandMaterial.h"
#include "OpenGLShaderUniformBuffer.h"
#include "OpenGLShader.h"
#include "OpenGLTexture.h"
#include "OpenGLRenderTarget.h"
#include <Laser/DrawStatus.h>
#include <Laser/Shader.h>
#include <Laser/Texture.h>
#include <Laser/RenderTarget.h>
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
					const MaterialTexture *pMaterialTexture = &texture.second;
					OpenGLTexture *pTexture = pMaterialTexture->mTexture;

					if( pTexture->IsAvailable() ) {
						GLuint SamplerUniformIndex = 0;
						if(	mShaderProgram.GetTextureIndex( pMaterialTexture->mName, &SamplerUniformIndex ) ) {
							pTexture->UpdateParameter( false );
							glActiveTexture( GL_TEXTURE0 + index );
							glBindTexture( GL_TEXTURE_2D, pTexture->GetHandle() );
							glUniform1i( SamplerUniformIndex, pTexture->GetHandle() );
						}
					}
				}
				
				BOOST_FOREACH( RenderTargetsType::value_type &rendertarget, mRenderTargets ) {
					uint32_t index = rendertarget.first;
					const MaterialRenderTarget *pMaterialRenderTarget = &rendertarget.second;
					const OpenGLRenderTarget *pRenderTarget = pMaterialRenderTarget->mRenderTarget;
					
					if( pRenderTarget->IsAvailable() ) {
						GLuint SamplerUniformIndex = 0;
						if( mShaderProgram.GetTextureIndex( pMaterialRenderTarget->mName, &SamplerUniformIndex ) ) {
							glActiveTexture( GL_TEXTURE0 + index );
							glBindTexture( GL_TEXTURE_2D, pRenderTarget->GetHandle() );
							glUniform1i( GL_TEXTURE_2D, pRenderTarget->GetHandle() );
						}
					}
				}

				if( mState[ STATE_BLEND ] ) {
					boost::array< GLenum, BLEND_MAX > blends = {
						GL_ZERO,
						GL_ONE,
						GL_SRC_COLOR,
						GL_ONE_MINUS_SRC_COLOR,
						GL_DST_COLOR,
						GL_ONE_MINUS_DST_COLOR,
						GL_SRC_ALPHA,
						GL_ONE_MINUS_SRC_ALPHA,
						GL_DST_ALPHA,
						GL_ONE_MINUS_DST_ALPHA,
						GL_CONSTANT_COLOR,
						GL_ONE_MINUS_CONSTANT_COLOR,
						GL_CONSTANT_ALPHA,
						GL_ONE_MINUS_CONSTANT_ALPHA,
						GL_SRC_ALPHA_SATURATE,
						GL_SRC1_COLOR,
						GL_ONE_MINUS_SRC1_COLOR,
						GL_SRC1_ALPHA,
						GL_ONE_MINUS_SRC1_ALPHA
					};
					glEnable( GL_BLEND );
					glBlendFunc( blends[mBlendSource], blends[mBlendDest] );
				} else {
					glEnable( GL_BLEND );
				}

				if( mState[ STATE_DEPTH ] ) {
					boost::array< GLenum, DEPTH_MAX > depthfuncs = {
						GL_NEVER,
						GL_LESS,
						GL_EQUAL,
						GL_LEQUAL,
						GL_GREATER,
						GL_NOTEQUAL,
						GL_GEQUAL,
						GL_ALWAYS
					};
					glEnable( GL_DEPTH_TEST );
					glDepthFunc( depthfuncs[mDepthFunc] );
				} else {
					glDisable( GL_DEPTH_TEST );
				}

				if( mState[ STATE_STENCIL ] ) {
					boost::array< GLenum, STENCIL_MAX > stencilfuncs = {
						GL_NEVER,
						GL_LESS,
						GL_LEQUAL,
						GL_GREATER,
						GL_GEQUAL,
						GL_EQUAL,
						GL_NOTEQUAL,
						GL_ALWAYS
					};
					glEnable( GL_STENCIL_TEST );
					glStencilFunc( stencilfuncs[ mStencilFunc ], mStencilRef, mStencilMask );
				} else {
					glDisable( GL_STENCIL_TEST );
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

		bool OpenGLMaterial::SetTexture( unsigned int index, const TGUL::String &name, Texture *pTexture )
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

			mTextures[index] = MaterialTexture( name, static_cast< Laser::OpenGLTexture * >( pTextureBuf ) );

			return true;
		}
		
		bool OpenGLMaterial::SetRenderTarget( const TGUL::String &name, RenderTarget *pRenderTarget )
		{
			void *pRenderTargetBuf = 0;
			if( pRenderTarget->QueryInterface( UUIDS::OPENGL_RENDER_TARGET, &pRenderTargetBuf ) == false ) {
				return false;
			}
			
			mRenderTargets[0] = MaterialRenderTarget( name, static_cast< Laser::OpenGLRenderTarget * >( pRenderTargetBuf ) );
			
			return true;
		}

	}

}