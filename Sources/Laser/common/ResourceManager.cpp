#include <Laser/ResourceManager.h>
#include <Laser/Buffer.h>
#include <Laser/Shader.h>
#include <Laser/Texture.h>
#include <Laser/RenderTarget.h>
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
		typedef std::map< TGUL::String, Texture * > TexturesType;
		typedef std::map< TGUL::String, RenderTarget * > RenderTargetsType;
		BuffersType mBuffers;
		ShadersType mShaders;
		TexturesType mTextures;
		RenderTargetsType mRenderTargets;
		
	public:
		void Execute( );
		bool AddShader( const TGUL::String &ShaderName, Shader &shader );
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;
		
		bool AddBuffer( const TGUL::String &BufferName, Resource::Buffer &buffer );
		bool GetBuffer( const TGUL::String &BufferName, Resource::Buffer **ppBuffer ) const;

		bool AddTexture( const TGUL::String &BufferName, Texture &buffer );
		bool GetTexture( const TGUL::String &BufferName, Texture **ppBuffer ) const;

		bool AddRenderTarget( const TGUL::String &RenderTargetName, RenderTarget &rendertarget );
		bool GetRenderTarget( const TGUL::String &RenderTargetName, RenderTarget **ppRenderTarget ) const;
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
	
	bool ResourceManager::Impl::AddBuffer( const TGUL::String &name, Resource::Buffer &buffer )
	{
		if( mBuffers.find( name ) != mBuffers.end() ) {
			return false;
		}
		
		mBuffers.insert( BuffersType::value_type( name, &buffer ) );
		return true;
	}
	
	bool ResourceManager::Impl::GetBuffer( const TGUL::String &BufferName, Resource::Buffer **ppBuffer ) const
	{
		BuffersType::const_iterator i = mBuffers.find( BufferName );
		if( i == mBuffers.end() ) {
			return false;
		}
		
		BuffersType::value_type result = *i;
		*ppBuffer = result.second;
		
		return true;
	}
			
	bool ResourceManager::Impl::AddTexture( const TGUL::String &name, Texture &texture )
	{
		if( mTextures.find( name ) != mTextures.end() ) {
			return false;
		}
		
		mTextures.insert( TexturesType::value_type( name, &texture ) );
		return true;
	}
	
	bool ResourceManager::Impl::GetTexture( const TGUL::String &BufferName, Texture **ppTexture ) const
	{
		TexturesType::const_iterator i = mTextures.find( BufferName );
		if( i == mTextures.end() ) {
			return false;
		}
		
		TexturesType::value_type result = *i;
		*ppTexture = result.second;
		
		return true;
	}

	bool ResourceManager::Impl::AddRenderTarget( const TGUL::String &name, RenderTarget &rendertarget )
	{
		if( mRenderTargets.find( name ) != mRenderTargets.end() ) {
			return false;
		}
		
		mRenderTargets.insert( RenderTargetsType::value_type( name, &rendertarget ) );
		return true;
	}
	
	bool ResourceManager::Impl::GetRenderTarget( const TGUL::String &BufferName, RenderTarget **ppRenderTarget ) const
	{
		RenderTargetsType::const_iterator i = mRenderTargets.find( BufferName );
		if( i == mRenderTargets.end() ) {
			return false;
		}
		
		RenderTargetsType::value_type result = *i;
		*ppRenderTarget = result.second;
		
		return true;
	}

	void ResourceManager::Impl::Execute( )
	{
		BOOST_FOREACH( ShadersType::value_type &shader, mShaders ) {
			shader.second->Execute();
		}
		BOOST_FOREACH( TexturesType::value_type &texture, mTextures ) {
			texture.second->Execute();
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

	bool ResourceManager::GetBuffer( const TGUL::String &BufferName, Resource::Buffer **ppBuffer ) const
	{
		return mImpl->GetBuffer( BufferName, ppBuffer );
	}

	bool ResourceManager::GetTexture( const TGUL::String &TextureName, Texture **ppTexture ) const
	{
		return mImpl->GetTexture( TextureName, ppTexture );
	}

	bool ResourceManager::GetRenderTarget( const TGUL::String &RenderTargetName, RenderTarget **ppRenderTarget ) const
	{
		return mImpl->GetRenderTarget( RenderTargetName, ppRenderTarget );
	}

	bool ResourceManager::AddShader( const TGUL::String &name, Shader &shader )
	{
		return mImpl->AddShader( name, shader );
	}
	
	bool ResourceManager::AddBuffer( const TGUL::String &name, Resource::Buffer &buffer )
	{
		return mImpl->AddBuffer( name, buffer );
	}

	bool ResourceManager::AddTexture( const TGUL::String &name, Texture &texture )
	{
		return mImpl->AddTexture( name, texture );
	}

	bool ResourceManager::AddRenderTarget( const TGUL::String &name, RenderTarget &rendertarget )
	{
		return mImpl->AddRenderTarget( name, rendertarget );
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