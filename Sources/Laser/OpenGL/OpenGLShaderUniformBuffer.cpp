#include "OpenGLShaderUniformBuffer.h"
#include <TGUL/String.h>

namespace Laser
{
	OpenGLShaderUniformBuffer::OpenGLShaderUniformBuffer()
	: mHandle( 0 )
	{
	}

	bool OpenGLShaderUniformBuffer::Create( )
	{
		if( mHandle != 0 ) {
			return false;
		}
		glGenBuffers( 1, &mHandle );

		return true;
	}

	bool OpenGLShaderUniformBuffer::Update( const ShaderUniformBufferClassBase &base )
	{

		if( mHandle == 0 ) {
			return false;
		}

		glBindBuffer( GL_UNIFORM_BUFFER, mHandle );
		glBufferData( GL_UNIFORM_BUFFER, base.GetSize(), base.GetData(), GL_DYNAMIC_DRAW );

		return true;
	}
	
	void OpenGLShaderUniformBuffer::Bind( int location, const TGUL::String &name )
	{
		mLocation = location;
		mName = name;
	}
	
	bool OpenGLShaderUniformBuffer::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == Object::GetUUID() ||
		   uuid == Buffer::GetUUID() || uuid == ShaderUniformBuffer::GetUUID() || uuid == OpenGLShaderUniformBuffer::GetUUID() ) {
			*ppObject = this;
			return true;
		}
		
		return false;
	}

}