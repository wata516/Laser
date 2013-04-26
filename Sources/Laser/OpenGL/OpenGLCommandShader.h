#pragma once

#include <Laser/CommandShader.h>
#include <boost/array.hpp>
#include <GL/glfw.h>

namespace Laser
{
	namespace Command
	{
		class OpenGLShader : public Command::Shader
		{
		public:
			OpenGLShader();

		public:
			void Draw();
			virtual void SetShader( ShaderType type, const Laser::Shader *pShader );

		private:
			boost::array< const Laser::Shader *, SHADER_TYPE_MAX > mShaders;
		};
	}
}