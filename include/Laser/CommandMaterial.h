#pragma once

#include <Laser/IBase.h>
#include <bitset>

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

		public:
			enum BlendType {
				BLEND_ZERO,
				BLEND_ONE,
				BLEND_SRC_COLOR,
				BLEND_ONE_MINUS_SRC_COLOR,
				BLEND_DST_COLOR,
				BLEND_ONE_MINUS_DST_COLOR,
				BLEND_SRC_ALPHA,
				BLEND_ONE_MINUS_SRC_ALPHA,
				BLEND_DST_ALPHA,
				BLEND_ONE_MINUS_DST_ALPHA,
				BLEND_CONSTANT_COLOR,
				BLEND_ONE_MINUS_CONSTANT_COLOR,
				BLEND_CONSTANT_ALPHA,
				BLEND_ONE_MINUS_CONSTANT_ALPHA,
				BLEND_SRC_ALPHA_SATURATE,
				BLEND_SRC1_COLOR,
				BLEND_ONE_MINUS_SRC1_COLOR,
				BLEND_SRC1_ALPHA,
				BLEND_ONE_MINUS_SRC1_ALPHA,
				BLEND_MAX
			};
			enum DepthType {
				DEPTH_NEVER,
				DEPTH_LESS,
				DEPTH_EQUAL,
				DEPTH_LEQUAL,
				DEPTH_GREATER,
				DEPTH_NOTEQUAL,
				DEPTH_GEQUAL,
				DEPTH_ALWAYS,
				DEPTH_MAX
			};
			enum StencilType {
				STENCIL_NEVER,
				STENCIL_LESS,
				STENCIL_LEQUAL,
				STENCIL_GREATER,
				STENCIL_GEQUAL,
				STENCIL_EQUAL,
				STENCIL_NOTEQUAL,
				STENCIL_ALWAYS,
				STENCIL_MAX
			};
			enum StateType {
				STATE_BLEND,
				STATE_DEPTH,
				STATE_STENCIL,
				STATE_MAX
			};
		public:
			Material();

		public:
			virtual bool Create( Shader *pVertexShader, Shader *pFragmentShader, ShaderUniformBuffer *pShaderUniformBuffer ) = 0;
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name ) = 0;
			virtual bool SetTexture( unsigned int index, const TGUL::String &name, Texture *pTexture ) = 0;
			virtual bool SetRenderTarget( const TGUL::String &name, RenderTarget *pRenderTarget ) = 0;
			virtual bool IsAvailable() const = 0;

		public:
			void SetState( StateType state, bool flag ) { mState[state] = flag; }
			void SetStencil( int ref, unsigned int mask ) { mStencilRef = ref; mStencilMask = mask; }

		protected:
			ShaderUniformBuffer * mShaderUniformBuffers;
			BlendType mBlendSource, mBlendDest;
			DepthType mDepthFunc;
			StencilType mStencilFunc;
			int mStencilRef;
			unsigned int mStencilMask;
			std::bitset< STATE_MAX > mState;

		};
	}
}