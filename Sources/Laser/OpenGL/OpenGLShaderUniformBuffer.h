#pragma once

#include <Laser/ShaderUniformBuffer.h>
#include <TGUL/String.H>
#include <GL/glew.h>

namespace Laser
{
	class ShaderUniformBufferClassBase;
	class OpenGLShaderUniformBuffer : public ShaderUniformBuffer
	{
	public:
		OpenGLShaderUniformBuffer();

	public:
		static const UUID &GetUUID( ) { return UUIDS::OPENGL_SHADER_UNIFORM_BUFFER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Create();
		virtual bool Update( const ShaderUniformBufferClassBase &base );
		
		void Bind( int location, const TGUL::String &name );
		GLuint GetHandle() const { return mHandle; }
		const TGUL::String &GetName() const { return mName; }

	private:
		GLuint mHandle;
		int mLocation;
		TGUL::String mName;
	};
}
