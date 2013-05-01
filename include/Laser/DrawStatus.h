#pragma once

#include <Laser/CommandShader.h>
#include <boost/array.hpp>

namespace Laser
{
	class Shader;
	class DrawStatus
	{
	public:
		void SetShader( Command::Shader::ShaderType type, Shader *pShader ) { mShaders[ type ] = pShader; }
		Shader *GetShader( Command::Shader::ShaderType type ) { return mShaders[type]; }

	private:
		boost::array< Shader *, Command::Shader::SHADER_TYPE_MAX > mShaders;
	};
}
