#pragma once

#include <Laser/IndexBuffer.h>
#include <GL/glew.h>

namespace Laser
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer();

	public:
		virtual bool Create( IndexSize type, unsigned int IndexNum );
		virtual bool Write( WriteType WriteFunction );

		GLuint GetHandle() const { return mBuffer; }
	private:
		IndexSize mIndexSize;
		GLuint mBuffer;
		unsigned int mIndexNum;
	};
}