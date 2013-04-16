#pragma once

namespace TGUL {
    class String;
}

namespace Laser {
    namespace System
    {
        class IManager;
    }
}

namespace Laser
{
    namespace System
    {
        class ManagerFactory
        {
        public:
            //! @brief  マネージャーを作成します
            //! @param  name    OpenGL  OpenGLのマネージャーを作成する.
            static bool Create( const TGUL::String &name, IManager **ppManager );
            
        };
    }
}