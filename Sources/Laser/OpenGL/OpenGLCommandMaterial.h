#pragma once

#include <Laser/CommandMaterial.h>
#include "OpenGLShaderProgram.h"
#include <TGUL/String.h>
#include <boost/unordered_map.hpp>

namespace Laser
{
	class OpenGLShaderUniformBuffer;
	class OpenGLTexture;
	class OpenGLRenderTarget;
	class ShaderUniformBuffer;
	class Shader;
	class Texture;
	class RenderTarget;
	namespace Command
	{
		class OpenGLMaterial : public Command::Material
		{
			struct MaterialTexture {
				MaterialTexture() {}
				explicit MaterialTexture( const TGUL::String &name, OpenGLTexture *pTexture ) : mName(name), mTexture( pTexture ){}
				TGUL::String mName;
				OpenGLTexture *mTexture;
			};
			struct MaterialRenderTarget {
				MaterialRenderTarget() {}
				explicit MaterialRenderTarget( const TGUL::String &name, OpenGLRenderTarget *pRenderTarget )
				: mName(name), mRenderTarget( pRenderTarget ){}
				TGUL::String mName;
				OpenGLRenderTarget *mRenderTarget;
			};
			typedef boost::unordered_map<uint32_t, MaterialTexture > TexturesType;
			enum {
				TEXTURE_MAX = 10
			};
			typedef boost::unordered_map<uint32_t, MaterialRenderTarget > RenderTargetsType;
		public:
			OpenGLMaterial();

		public:
			virtual bool Create( Laser::Shader *pVertexShader, Laser::Shader *pFragmentShader, ShaderUniformBuffer *pUniformBuffer );
			virtual void Draw( DrawStatus &Status );
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name );
			virtual bool IsAvailable() const;

			virtual bool SetTexture( uint32_t index, const TGUL::String &name, Texture *pTexture );
			virtual bool SetRenderTarget( const TGUL::String &name, RenderTarget *pRenderTarget );

		private:
			OpenGLShaderUniformBuffer *mShaderUniformBuffer;
			TexturesType mTextures;
			OpenGLShaderProgram mShaderProgram;
			RenderTargetsType mRenderTargets;
		};
	}
}
