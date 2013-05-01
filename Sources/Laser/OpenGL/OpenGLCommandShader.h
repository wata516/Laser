#pragma once

#include <Laser/CommandShader.h>
#include <Laser/VertexDeclare.h>
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
			virtual void Draw( DrawStatus &Status );
			virtual Laser::Shader *GetShader( ShaderType type ) const;
			virtual void SetShader( ShaderType type, Laser::Shader *pShader );
			virtual bool Create( );
			
			virtual bool IsAvailable() const;

		private:
			boost::array< Laser::OpenGLShader *, SHADER_TYPE_MAX > mShaders;
			GLuint mProgram;
			bool mIsAvailable;
		};
	}
}