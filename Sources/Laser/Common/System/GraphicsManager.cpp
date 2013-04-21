#include <Laser/Common/System/GraphicsManager.h>
#include <Laser/Common/System/TechniqueManager.h>
#include <Laser/Common/Resource/ResourceManager.h>
#include <TGUL/String.h>

namespace Laser
{
		class GraphicsManager::Impl
		{
			TGUL::String mName;

		public:
			Impl( const TGUL::String &name );

		public:
			const TGUL::String &GetFactoryName() const { return mName; }
		};
		
		GraphicsManager::Impl::Impl( const TGUL::String &name )
		: mName(name)
		{}
		
		GraphicsManager::GraphicsManager()
		{
		}
		
		GraphicsManager::GraphicsManager( const TGUL::String &name )
		: mImpl( boost::shared_ptr<Impl>( new Impl( name )) )
		, mResourceManager( 0 )
		{}

		const TGUL::String &GraphicsManager::GetFactoryName() const
		{ return mImpl->GetFactoryName(); }

}