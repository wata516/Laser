#include "OpenGLCommandMaterial.h"
#include "OpenGLShaderUniformBuffer.h"
#include <boost/foreach.hpp>

namespace Laser
{
	namespace Command
	{
		void OpenGLMaterial::UpdateShaderUniformBuffer( const ShaderUniformBufferClassBase &base )
		{
			mShaderUniformBuffer->Update(base);
			mShaderUniformBuffer->Bind(base.GetLocation());
		}

		void OpenGLMaterial::Draw()
		{
		}

	
		bool OpenGLMaterial::Create( ShaderUniformBuffer *pUniformBuffer )
		{
			void *pUniBuf = 0;
			if( pUniformBuffer->QueryInterface( UUIDS::OPENGL_SHADER_UNIFORM_BUFFER, &pUniBuf ) == false ) {
			
				return false;
			}
			mShaderUniformBuffer = static_cast< Laser::OpenGLShaderUniformBuffer * >( pUniBuf );

			return true;
		}
	}

}