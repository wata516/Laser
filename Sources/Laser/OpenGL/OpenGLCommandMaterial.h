#pragma once

#include <Laser/CommandMaterial.h>

namespace TGUL
{
	class String;
}

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
			virtual void Draw( DrawStatus &Status );
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name );

		private:
			OpenGLShaderUniformBuffer *mShaderUniformBuffer;
		};
	}
}
