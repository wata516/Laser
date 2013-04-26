#pragma once

#include <Laser/Shader.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLShader : public Shader
	{
	public:
		GLuint GetShader() const { return mShader; }

	protected:
		bool CompileShader( GLint ShaderType, const GLchar *pSourceCode, GLint SourceCodeSize );

	private:
		GLuint mShader;
	};
}