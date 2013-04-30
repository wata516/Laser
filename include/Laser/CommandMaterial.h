#pragma once

#include <Laser/IBase.h>

namespace Laser
{
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

			virtual bool Create( ShaderUniformBuffer *pShaderUniformBuffer ) = 0;
			
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base ) = 0;

		protected:
			ShaderUniformBuffer * mShaderUniformBuffers;

		};
	}
}