#include <Laser/TechniqueManager.h>
#include <Laser/ITechnique.h>
#include <boost/foreach.hpp>

namespace Laser
{
	class TechniqueManager::Impl
	{
	public:
		bool Regist(const User::ITechnique &technique);
		void Render( const TechniqueManager::technique_list &techniques ) const;
	};

	void TechniqueManager::Impl::Render( const TechniqueManager::technique_list &techniques) const
	{
		BOOST_FOREACH( const technique_ptr technique, techniques ) {
			technique->Render();
		}
	}

	TechniqueManager::TechniqueManager()
		: mImpl( new Impl )
	{}

	void TechniqueManager::Render( ) const
	{
		mImpl->Render( mTechniques );
	}
}