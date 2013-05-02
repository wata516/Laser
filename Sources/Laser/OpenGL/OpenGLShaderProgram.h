#pragma once

#include <Laser/VertexDeclare.h>
#include <boost/array.hpp>
#include <GL/glew.h>

namespace Laser
{
	class Shader;
	class OpenGLShader;
	class OpenGLShaderProgram
	{
		enum ShaderType
		{
			SHADER_TYPE_VERTEX,
			SHADER_TYPE_FRAGMENT,
			SHADER_TYPE_MAX
		};

	public:
		OpenGLShaderProgram();

	public:
		void Draw( );
		bool Create( Shader *pVertexShader, Shader *pFragmentShader );
		bool CreateProgram( );

		bool IsAvailable() const;
		GLuint GetHandle() const { return mProgram; }
		bool GetUniformIndex( const TGUL::String &Name, GLuint *pIndex ) const;

	private:
		boost::array< Laser::OpenGLShader *, SHADER_TYPE_MAX > mShaders;
		GLuint mProgram;
		bool mIsAvailable;
	};
}