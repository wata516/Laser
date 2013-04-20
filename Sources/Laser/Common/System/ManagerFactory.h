#pragma once

namespace TGUL {
    class String;
}

namespace Laser {
    namespace System
    {
        class Manager;
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
            static bool Create( const TGUL::String &name, Manager **ppManager );
            
        };
    }
}