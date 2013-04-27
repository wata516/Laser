#pragma once

#include <Laser/VertexBuffer.h>
#include <boost/shared_array.hpp>
#include <GL/glew.h>

namespace Laser
{
	class VertexDeclare;
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer();

	public:
		virtual bool Write( WriteType WriteFunction );
				
	public:
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		GLuint GetHandle() const { return mHandle; }

	private:
		boost::shared_array< GLuint > mVertexBuffers;
		GLuint mHandle;
	};
}