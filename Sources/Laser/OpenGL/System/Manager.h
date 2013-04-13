#pragma once

#include <Laser/Common/System/IManager.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace Laser
{
    namespace System
    {
        class OpenGLManager : public IManager, boost::noncopyable
        {
        public:
            OpenGLManager();
            
            virtual bool Create( );
            
            virtual void Destroy( );

        private:
            class Impl;
            boost::shared_ptr< Impl > mImpl;
        };
    }
}