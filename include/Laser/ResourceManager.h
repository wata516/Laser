#pragma once

#include <Laser/IResourceManager.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace Resource
	{
		class Buffer;
	}
}

namespace TGUL
{
	class String;
}

namespace Laser
{
	class Shader;
	class Buffer;

	class ResourceManager : IResourceManager
	{
	public:
		ResourceManager();

	public:
		virtual bool CreateBuffer( const TGUL::String &CreateName, const TGUL::String &BufferName, Resource::Buffer **ppBuffer ) = 0;
		virtual bool CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader ) = 0;
		
		void Execute();

	public:
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;
		bool GetBuffer( const TGUL::String &BufferName, Resource::Buffer **ppBuffer ) const;

	protected:
		bool AddShader( const TGUL::String &name, Shader &shader );
		bool AddBuffer( const TGUL::String &name, Resource::Buffer &buffer );

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
