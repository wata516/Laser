#include <Laser/ResourceManager.h>
#include <Laser/Buffer.h>
#include <Laser/Shader.h>
#include <Laser/Texture.h>
#include <Laser/ShaderUniformBuffer.h>
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
		typedef std::map< TGUL::String, VertexBuffer * > VertexBuffersType;
		typedef std::map< TGUL::String, IndexBuffer * > IndexBuffersType;
		typedef std::map< TGUL::String, ShaderUniformBuffer * > UniformBuffersType;
		typedef std::map< TGUL::String, Texture * > TexturesType;
		typedef std::map< TGUL::String, RenderTarget * > RenderTargetsType;
		VertexBuffersType mVertexBuffers;
		IndexBuffersType mIndexBuffers;
		UniformBuffersType mUniformBuffers;
		ShadersType mShaders;
		TexturesType mTextures;
		RenderTargetsType mRenderTargets;
		
	public:
		void Execute( );
		bool AddShader( const TGUL::String &ShaderName, Shader &shader );
		bool GetShader( const TGUL::String &ShaderName, Shader **ppShader ) const;
		
		bool AddVertexBuffer( const TGUL::String &BufferName, VertexBuffer &buffer );
		bool GetVertexBuffer( const TGUL::String &BufferName, VertexBuffer **ppBuffer ) const;

		bool AddIndexBuffer( const TGUL::String &BufferName, IndexBuffer &buffer );
		bool GetIndexBuffer( const TGUL::String &BufferName, IndexBuffer **ppBuffer ) const;

		bool AddUniformBuffer( const TGUL::String &BufferName, ShaderUniformBuffer &buffer );
		bool GetUniformBuffer( const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer ) const;

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
	
	bool ResourceManager::Impl::AddVertexBuffer( const TGUL::String &name, VertexBuffer &buffer )
	{
		if( mVertexBuffers.find( name ) != mVertexBuffers.end() ) {
			return false;
		}
		
		mVertexBuffers.insert( VertexBuffersType::value_type( name, &buffer ) );
		return true;
	}
	
	bool ResourceManager::Impl::GetVertexBuffer( const TGUL::String &BufferName, VertexBuffer **ppBuffer ) const
	{
		VertexBuffersType::const_iterator i = mVertexBuffers.find( BufferName );
		if( i == mVertexBuffers.end() ) {
			return false;
		}
		
		VertexBuffersType::value_type result = *i;
		*ppBuffer = result.second;
		
		return true;
	}

	bool ResourceManager::Impl::AddIndexBuffer( const TGUL::String &name, IndexBuffer &buffer )
	{
		if( mIndexBuffers.find( name ) != mIndexBuffers.end() ) {
			return false;
		}

		mIndexBuffers.insert( IndexBuffersType::value_type( name, &buffer ) );
		return true;
	}

	bool ResourceManager::Impl::GetIndexBuffer( const TGUL::String &BufferName, IndexBuffer **ppBuffer ) const
	{
		IndexBuffersType::const_iterator i = mIndexBuffers.find( BufferName );
		if( i == mIndexBuffers.end() ) {
			return false;
		}

		IndexBuffersType::value_type result = *i;
		*ppBuffer = result.second;

		return true;
	}

	bool ResourceManager::Impl::AddUniformBuffer( const TGUL::String &name, ShaderUniformBuffer &buffer )
	{
		if( mUniformBuffers.find( name ) != mUniformBuffers.end() ) {
			return false;
		}

		mUniformBuffers.insert( UniformBuffersType::value_type( name, &buffer ) );
		return true;
	}

	bool ResourceManager::Impl::GetUniformBuffer( const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer ) const
	{
		UniformBuffersType::const_iterator i = mUniformBuffers.find( BufferName );
		if( i == mUniformBuffers.end() ) {
			return false;
		}

		UniformBuffersType::value_type result = *i;
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

	bool ResourceManager::GetVertexBuffer( const TGUL::String &BufferName, VertexBuffer **ppBuffer ) const
	{
		return mImpl->GetVertexBuffer( BufferName, ppBuffer );
	}

	bool ResourceManager::GetIndexBuffer( const TGUL::String &BufferName, IndexBuffer **ppBuffer ) const
	{
		return mImpl->GetIndexBuffer( BufferName, ppBuffer );
	}
	bool ResourceManager::GetUniformBuffer( const TGUL::String &BufferName, ShaderUniformBuffer **ppBuffer ) const
	{
		return mImpl->GetUniformBuffer( BufferName, ppBuffer );
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
	
	bool ResourceManager::AddVertexBuffer( const TGUL::String &name, VertexBuffer &buffer )
	{
		return mImpl->AddVertexBuffer( name, buffer );
	}

	bool ResourceManager::AddIndexBuffer( const TGUL::String &name, IndexBuffer &buffer )
	{
		return mImpl->AddIndexBuffer( name, buffer );
	}

	bool ResourceManager::AddUniformBuffer( const TGUL::String &name, ShaderUniformBuffer &buffer )
	{
		return mImpl->AddUniformBuffer( name, buffer );
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