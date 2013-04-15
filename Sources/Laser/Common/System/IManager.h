#pragma once

namespace Laser
{
	namespace System
	{
		class IWindow;
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
        class IManager
        {
        public:
            //! @brief  作成.
            virtual bool Create( ) = 0;
            
            //! @brief  終了処理.
            virtual void Destroy( ) = 0;
            
			//!	@brief	ウィンドウを作成.
			virtual bool CreateWindow( IWindow **ppWindow ) = 0;

			//!	@brief	キーボードを作成.
			virtual bool CreateKeyboard( Input::IKeyboard **ppKeyboard ) = 0;
        };
    }
}