#pragma once

namespace TGUL {
    class String;
}

namespace Laser {
	class GraphicsManager;
}

namespace Laser
{
        class GraphicsManagerFactory
        {
        public:
            //! @brief  マネージャーを作成します
            //! @param  name    OpenGL  OpenGLのマネージャーを作成する.
            static bool Create( const TGUL::String &name, GraphicsManager **ppManager );
            
        };
}