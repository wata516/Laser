#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class Shader;
	class Texture;
	class RenderTarget;
	class ShaderUniformBuffer;
	class ShaderUniformBufferBase;
	class ShaderUniformBufferClassBase;
	namespace Command
	{
		class Material : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_MATERIAL > ID;
			
		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_MATERIAL;}

			virtual bool Create( Shader *pVertexShader, Shader *pFragmentShader, ShaderUniformBuffer *pShaderUniformBuffer ) = 0;
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name ) = 0;
			virtual bool SetTexture( uint32_t index, const TGUL::String &name, Texture *pTexture ) = 0;
			virtual bool SetRenderTarget( const TGUL::String &name, RenderTarget *pRenderTarget ) = 0;
			virtual bool IsAvailable() const = 0;

		protected:
			ShaderUniformBuffer * mShaderUniformBuffers;

		};
	}
}