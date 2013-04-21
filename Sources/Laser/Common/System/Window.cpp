#include <Laser/Common/System/Window.h>
#include <Laser/Common/System/TechniqueManager.h>

namespace Laser
{
	class Window::Impl
	{
		const TechniqueManager *mTechniqueManager;
	public:
		void Render( ) const;
		void SetTechnique(const TechniqueManager *pTechniqueManager);
	};

	void Window::Impl::Render( ) const
	{
		mTechniqueManager->Render();
	}
	void Window::Impl::SetTechnique(const TechniqueManager *pTechniqueManager)
	{
		mTechniqueManager = pTechniqueManager;
			
	}
		
	Window::Window( )
	: mImpl( new Impl )
	{}

	void Window::Render( ) const
	{
		mImpl->Render();
	}

	void Window::SetTechnique(const TechniqueManager *pTechniqueManager)
	{
		mImpl->SetTechnique( pTechniqueManager );
	}
}