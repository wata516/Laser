#include <Laser/ResourceManager.h>
#include <Laser/Buffer.h>
#include <Laser/Shader.h>
#include "BufferFactory.h"
#include <TGUL/String.h>
#include <map>
#include <boost/foreach.hpp>

namespace Laser
{
	class ResourceManager::Impl
	{
		typedef std::map< TGUL::String, Shader * > ShadersType;
		typedef std::map< TGUL::String, Resource::Buffer * > BuffersType;
		BuffersType mBuffers;
		ShadersType mShaders;
		
	public:
		void Execute( );
		bool AddShader( const TGUL::String &name, Shader &shader );
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;
	};
	
	bool ResourceManager::Impl::AddShader( const TGUL::String &name, Shader &shader )
	{
		if( mShaders.find( name ) != mShaders.end() ) {
			return false;
		}

		mShaders.insert( ShadersType::value_type( name, &shader ) );
		return true;
	}

	bool ResourceManager::Impl::GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const
	{
		ShadersType::const_iterator i = mShaders.find( ShaderName );
		if( i == mShaders.end() ) {
			return false;
		}

		ShadersType::value_type result = *i;
		*ppShader = result.second;

		return true;
	}
		
	bool ResourceManager::CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const
	{
		if( Resource::BufferFactory::Create( name, ppBuffer ) == false ) {
			return false;
		}
		return true;
	}
	
	void ResourceManager::Impl::Execute( )
	{
		BOOST_FOREACH( ShadersType::value_type &shader, mShaders ) {
			shader.second->Execute();
		}
	}

	ResourceManager::ResourceManager()
	: mImpl( new Impl )
	{}

	void ResourceManager::Execute()
	{
		mImpl->Execute();
	}
	
	bool ResourceManager::GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const
	{
		return mImpl->GetShader( ShaderName, ppShader );
	}

	bool ResourceManager::AddShader( const TGUL::String &name, Shader &shader )
	{
		return mImpl->AddShader( name, shader );
	}

	bool IResourceManager::QueryInterface( const UUID &uuid, void **ppObject )
	{
		if( uuid == GetUUID() || uuid == UUIDS::OBJECT || uuid == UUIDS::IUNKNOWN) {
			*ppObject = this;
			return true;
		}

		return false;
	}

}