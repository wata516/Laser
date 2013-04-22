#pragma once

#include <Laser/IGraphicsManager.h>
#include <boost/shared_ptr.hpp>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class TechniqueManager;
	class ResourceManager;
}

namespace Laser
{
	class GraphicsManager : public IGraphicsManager
	{
	public:
		GraphicsManager();
		GraphicsManager( const TGUL::String &name );

	public:
		const TGUL::String &GetFactoryName() const;
		const ResourceManager &GetResourceManager() const { return *mResourceManager; }

	protected:
		ResourceManager *mResourceManager;
	
	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}