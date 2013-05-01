#pragma once

#include <Laser/Shader.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader();

	public:
		GLuint GetShader() const { return mShader; }
		bool GetUniformIndex( const TGUL::String &Name, unsigned int *pIndex ) const;
		
		virtual bool IsAvailable( ) const;

	protected:
		bool CompileShader( GLint ShaderType, const GLchar *pSourceCode, GLint SourceCodeSize );

	private:
		GLuint mShader;
		bool mIsAvailable;
	};
}