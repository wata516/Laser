#include <Laser/OpenGL/System/Manager.h>
#include <GL/glfw.h>

namespace Laser
{
    namespace System
    {
        class OpenGLManager::Impl
        {
        public:
            bool Create( );
            void Destroy( );
        private:
            IWindow *mWindow;
        };

        bool OpenGLManager::Impl::Create( )
        {
            //glfwを初期化
            if( glfwInit() == GL_FALSE ) {
                return false;
            }
            
            // OpenGL 3.2を使用する
            glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
            glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
            glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            return true;
        }
        
        void OpenGLManager::Impl::Destroy( )
        {
            // glfwを終了
            glfwTerminate();
        }

        bool OpenGLManager::Create( )
        {
            return Impl->Create( );
        }
        void OpenGLManager::Destroy( )
        {
            Impl->Destroy( );
        }
    }
}