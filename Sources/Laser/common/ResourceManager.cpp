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
		typedef std::map< int, Shader * > ShadersType;
		std::map< Resource::Buffer *, boost::shared_ptr< Resource::Buffer > > mBuffers;
		ShadersType mShaders;
		
	public:
		void Execute( );
		void AddShader( Shader &shader );
	};
	
	void ResourceManager::Impl::AddShader( Shader &shader )
	{
		mShaders.insert( ShadersType::value_type( 0, &shader ) );
	}
		
	bool ResourceManager::CreateBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer ) const
	{
		return Resource::BufferFactory::Create( name, ppBuffer );
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
	
	void ResourceManager::AddShader( Shader &shader )
	{
		mImpl->AddShader( shader );
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