#pragma once

namespace Laser
{
	namespace System
	{
		class IWindow;
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
            
			//!	@brief	ウィンドウを開く.
			virtual bool CreateWindow( IWindow **ppWindow ) = 0;
        };
    }
}