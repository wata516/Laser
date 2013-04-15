#include <Laser/Common/System/TechniqueManager.h>
#include <Laser/Common/User/ITechnique.h>
#include <list>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace System
	{
		class TechniqueManager::Impl
		{
			std::list< User::ITechnique * > mTechniques;

		public:
			bool Regist(const User::ITechnique &technique);
		};
		
		bool TechniqueManager::Impl::Regist(const User::ITechnique &technique)
		{
			User::ITechnique *pBuff = reinterpret_cast< User::ITechnique * >( new uint8_t[ technique.GetClassSize() ] );
			
			if( pBuff == 0 ) {
				return false;
			}

			mTechniques.push_back( pBuff );
			
			return true;
		}

		TechniqueManager::TechniqueManager()
			: mImpl( new Impl )
		{}
		
		bool TechniqueManager::Regist(const User::ITechnique &technique)
		{
			return mImpl->Regist( technique );
		}
	}
}