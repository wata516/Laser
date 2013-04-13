#pragma once

namespace Laser
{
    namespace System
    {
        class IWindow
        {
        public:
            virtual bool Create( int32_t x, int32_t y, int32_t width, int32_t height ) = 0;
        };
    }
}