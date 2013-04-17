#pragma once

#include <Laser/Common/System/ITechniqueManager.h>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace Laser
{
	namespace User
	{
		class ITechnique;
	}
}

namespace Laser
{
	namespace System
	{
		class TechniqueManager : public ITechniqueManager
		{
		public:
			typedef boost::shared_ptr< const User::ITechnique > technique_ptr;
			typedef std::vector<technique_ptr> technique_list;

		public:
			TechniqueManager();

			bool Regist( const User::ITechnique &technique );
			void Render( ) const;
			template< typename T >
			bool Regist( const T &technique );

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
						
			technique_list mTechniques;
		};
		
		template< typename T >
		bool TechniqueManager::Regist(const T &technique)
		{
			const T *pNewTechnique = new T( technique );

			if( pNewTechnique == 0 ) {
				return false;
			}
			
			mTechniques.push_back( technique_ptr( pNewTechnique ) );
			
			return true;
		}
	}
}
