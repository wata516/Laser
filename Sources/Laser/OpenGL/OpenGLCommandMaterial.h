#pragma once

#include <Laser/CommandMaterial.h>
#include "OpenGLShaderProgram.h"

namespace TGUL
{
	class String;
}

namespace Laser
{
	class OpenGLShaderUniformBuffer;
	class ShaderUniformBuffer;
	class Shader;
	namespace Command
	{
		class OpenGLMaterial : public Command::Material
		{
		public:			
			virtual bool Create( Laser::Shader *pVertexShader, Laser::Shader *pFragmentShader, ShaderUniformBuffer *pUniformBuffer );
			virtual void Draw( DrawStatus &Status );
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name );
			virtual bool IsAvailable() const;

		private:
			OpenGLShaderUniformBuffer *mShaderUniformBuffer;
			OpenGLShaderProgram mShaderProgram;
		};
	}
}
