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

	class ResourceManager : IResourceManager
	{
	public:
		ResourceManager();

	public:
		bool CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const;
		virtual bool CreateShader( const TGUL::String &CreateName, const TGUL::String &ShaderName, Shader **ppShader ) = 0;
		
		void Execute();

	public:
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;

	protected:
		bool AddShader( const TGUL::String &name, Shader &shader );

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}
