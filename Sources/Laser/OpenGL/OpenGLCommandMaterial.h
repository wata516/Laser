#pragma once

#include <Laser/CommandMaterial.h>

namespace Laser
{
	class OpenGLShaderUniformBuffer;
	class ShaderUniformBuffer;
	namespace Command
	{
		class OpenGLMaterial : public Command::Material
		{
		public:			
			bool Create( ShaderUniformBuffer *pUniformBuffer );
			virtual void Draw();
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base );

		private:
			OpenGLShaderUniformBuffer *mShaderUniformBuffer;
		};
	}
}
