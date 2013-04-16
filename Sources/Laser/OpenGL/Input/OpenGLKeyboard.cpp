#include <Laser/OpenGL/Input/OpenGLKeyboard.h>
#include <boost/assign.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <map>
#include <bitset>
#include <GL/glfw.h>

namespace Laser
{
	namespace Input
	{
		class OpenGLKeyboard::Impl
		{
			static std::map< KEY_TYPE, int > mGLFWConvertTable;
			std::bitset< GLFW_KEY_LAST > mPress, mPrePress;
			boost::optional<int> GetGLFWKey( KEY_TYPE key );

		public:
			bool IsTrigger( KEY_TYPE key );
			bool IsPress( KEY_TYPE key );
			bool IsRelease( KEY_TYPE key );
			void Update( );
		};

		std::map< IKeyboard::KEY_TYPE, int > OpenGLKeyboard::Impl::mGLFWConvertTable = boost::assign::map_list_of
			( IKeyboard::KEY_TYPE_ESCAPE, GLFW_KEY_ESC )( IKeyboard::KEY_TYPE_SPACE, GLFW_KEY_SPACE );

		boost::optional<int> OpenGLKeyboard::Impl::GetGLFWKey( KEY_TYPE key )
		{
			if( mGLFWConvertTable.find( key ) == mGLFWConvertTable.end() ) {
				return boost::none;
			}
			return mGLFWConvertTable[key];
		}

		bool OpenGLKeyboard::Impl::IsTrigger( KEY_TYPE key )
		{
			boost::optional<int> result = GetGLFWKey( key );
			if( result == boost::none ) {
				return false;
			}

			return ((mPrePress[ *result ] == 0 ) && mPress[ *result ] )? true : false;
		}
		bool OpenGLKeyboard::Impl::IsPress( KEY_TYPE key )
		{
			boost::optional<int> result = GetGLFWKey( key ); 
			return ( result == boost::none ) ? false : mPress[ *result ];
		}
		bool OpenGLKeyboard::Impl::IsRelease( KEY_TYPE key )
		{
			return IsPress( key ) == false;
		}
		void OpenGLKeyboard::Impl::Update( )
		{
			mPrePress = mPress;
			mPress.reset();
			for( int i = 0 ; i < GLFW_KEY_LAST ; ++ i ) {
				mPress[i] = (glfwGetKey( i ) > 0 )?1:0;
			}
		}

		OpenGLKeyboard::OpenGLKeyboard()
			: mImpl( new Impl )
		{}
		bool OpenGLKeyboard::IsTrigger( KEY_TYPE key )
		{
			return mImpl->IsTrigger( key );
		}
		bool OpenGLKeyboard::IsPress( KEY_TYPE key )
		{
			return mImpl->IsPress( key );
		}
		bool OpenGLKeyboard::IsRelease( KEY_TYPE key )
		{
			return mImpl->IsRelease( key );
		}
		void OpenGLKeyboard::Update( )
		{
			mImpl->Update();
		}
		
	}
}