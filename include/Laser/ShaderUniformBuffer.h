#pragma once

#include <Laser/Buffer.h>
#include <TGUL/String.h>

namespace Laser
{
	class ShaderUniformBufferClassBase
	{
	public:
		ShaderUniformBufferClassBase( size_t size, const void *Buffer )
		: mSize( size )
		, mBuffer( Buffer )
		{}
	public:
		size_t GetSize() const { return mSize; }
		const void *GetData() const { return mBuffer; }

	private:
		size_t mSize;
		const void *mBuffer;
	};

	template< class T >
	class ShaderUniformBufferClass : public ShaderUniformBufferClassBase
	{
	public:
		enum {
			STRUCT_SIZE = sizeof( T )
		};
		
		ShaderUniformBufferClass( ) : ShaderUniformBufferClassBase( STRUCT_SIZE, &mBuffer )
		{}

		void Update( const T &buffer ) { mBuffer = buffer; }
						
		T &GetBuffer() { return mBuffer; }

	private:
		T mBuffer;
	};
	
	class ShaderUniformBuffer : public Resource::Buffer
	{

	public:
		static const UUID &GetUUID( ) { return UUIDS::SHADER_UNIFORM_BUFFER; }
		virtual bool QueryInterface( const UUID &uuid, void **ppObject );

	public:
		virtual bool Create( ) = 0;
		virtual bool Update( const ShaderUniformBufferClassBase &base ) = 0;
	};
	
}
