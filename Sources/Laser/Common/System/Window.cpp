#include <Laser/Common/System/Window.h>
#include <Laser/Common/System/TechniqueManager.h>

namespace Laser
{
	namespace System
	{
		class Window::Impl
		{
			const TechniqueManager *mTechniqueManager;
		public:
			void SetTechnique(const Laser::System::TechniqueManager *pTechniqueManager);
			
		};
		
		void Window::Impl::SetTechnique(const Laser::System::TechniqueManager *pTechniqueManager)
		{
			mTechniqueManager = pTechniqueManager;
			
		}
		
		Window::Window( )
		: mImpl( new Impl )
		{}
		void Window::SetTechnique(const Laser::System::TechniqueManager *pTechniqueManager)
		{
			mImpl->SetTechnique( pTechniqueManager );
		}
	}
}