#pragma once

//#include <Laser/Common/System/Object.h>

namespace Laser
{
	namespace System
	{
		class Window;
		class TechniqueManager;
	}

	namespace Input
	{
		class IKeyboard;
	}
}

namespace Laser
{
    namespace System
    {
        class IManager// : public Object
        {
        public:
            //! @brief  作成.
            virtual bool Create( ) = 0;
            
            //! @brief  終了処理.
            virtual void Destroy( ) = 0;
            
			//!	@brief	ウィンドウを作成.
			virtual bool CreateWindow( Window **ppWindow ) = 0;

			//!	@brief	TechniqueManagerを作成
			virtual bool CreateTechniqueManager( TechniqueManager **ppTechniqueManager ) = 0;

			//!	@brief	キーボードを作成.
			virtual bool CreateKeyboard( Input::IKeyboard **ppKeyboard ) = 0;			
        };
    }
}