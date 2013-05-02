#pragma once

#include <Laser/CommandMaterial.h>
#include "OpenGLShaderProgram.h"
#include <boost/unordered_map.hpp>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class OpenGLShaderUniformBuffer;
	class OpenGLTexture;
	class ShaderUniformBuffer;
	class Shader;
	class Texture;
	namespace Command
	{
		class OpenGLMaterial : public Command::Material
		{
			typedef boost::unordered_map<uint32_t, OpenGLTexture * > TexturesType;
			enum {
				TEXTURE_MAX = 10
			};
		public:
			OpenGLMaterial();

		public:
			virtual bool Create( Laser::Shader *pVertexShader, Laser::Shader *pFragmentShader, ShaderUniformBuffer *pUniformBuffer );
			virtual void Draw( DrawStatus &Status );
			virtual void UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base, int location, const TGUL::String &name );
			virtual bool IsAvailable() const;

			virtual bool SetTexture( uint32_t index, const TGUL::String &name, Texture *pTexture );
		private:
			OpenGLShaderUniformBuffer *mShaderUniformBuffer;
			TexturesType mTextures;
			OpenGLShaderProgram mShaderProgram;
		};
	}
}
