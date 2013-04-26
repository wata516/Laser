#pragma once

#include <Laser/CommandShader.h>
#include <boost/array.hpp>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLShader;
	namespace Command
	{
		class OpenGLShader : public Command::Shader
		{
		public:
			OpenGLShader();

		public:
			void Draw();
			virtual void SetShader( ShaderType type, Laser::Shader *pShader );
			virtual bool Create( );

		private:
			boost::array< Laser::OpenGLShader *, SHADER_TYPE_MAX > mShaders;
			GLuint mProgram;
		};
	}
}