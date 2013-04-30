#pragma once

#include <Laser/Buffer.h>

namespace Laser
{
	class ShaderUniformBufferClassBase
	{
	public:
		ShaderUniformBufferClassBase( int location, size_t size, const void *Buffer )
		: mLocation( location )
		, mSize( size )
		, mBuffer( Buffer )
		{}
	public:
		int GetLocation() const { return mLocation; }
		size_t GetSize() const { return mSize; }
		const void *GetData() const { return mBuffer; }

	private:
		int mLocation;
		size_t mSize;
		const void *mBuffer;
	};

	template< int location, class T >
	class ShaderUniformBufferClass : public ShaderUniformBufferClassBase
	{
	public:
		enum {
			LOCATION_INDEX = location,
			STRUCT_SIZE = sizeof( T )
		};
		
		//!	バッファを更新する
		void Update( const T &buffer ) { mBuffer = buffer; }
		
		ShaderUniformBufferClass( ) : ShaderUniformBufferClassBase( LOCATION_INDEX, STRUCT_SIZE, &mBuffer )
		{}
		
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
