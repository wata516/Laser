#include <Laser/Common/System/TechniqueManager.h>
#include <Laser/Common/User/ITechnique.h>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

namespace Laser
{
	namespace System
	{
		class TechniqueManager::Impl
		{
			typedef boost::shared_ptr< User::ITechnique > technique_ptr;
			typedef technique_ptr technique_const_ptr;

			std::list< technique_ptr > mTechniques;

		public:
			bool Regist(const User::ITechnique &technique);
			void Render( ) const;
		};
		
		bool TechniqueManager::Impl::Regist(const User::ITechnique &technique)
		{
			User::ITechnique * tec = reinterpret_cast< User::ITechnique * >( new uint8_t[ technique.GetClassSize() ] );
			
			memcpy( tec, &technique, technique.GetClassSize() );//.Clone();

			technique_ptr pBuff( tec );
			if( pBuff == 0 ) {
				return false;
			}
			mTechniques.push_back( pBuff );
			
			return true;
		}

		void TechniqueManager::Impl::Render( ) const
		{
			BOOST_FOREACH( technique_const_ptr technique, mTechniques ) {
				technique->Render();
			}

		}

		TechniqueManager::TechniqueManager()
			: mImpl( new Impl )
		{}
		
		bool TechniqueManager::Regist(const User::ITechnique &technique)
		{
			return mImpl->Regist( technique );
		}
		void TechniqueManager::Render( ) const
		{
			mImpl->Render();
		}
	}
}