#pragma once

#include <Laser/IKeyboard.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	namespace Input
	{
		class OpenGLKeyboard : public IKeyboard
		{
		public:
			OpenGLKeyboard();

		public:
			bool IsTrigger( KEY_TYPE key );
			bool IsPress( KEY_TYPE key );
			bool IsRelease( KEY_TYPE key );
			void Update( );

		private:
			class Impl;
			boost::shared_ptr<Impl> mImpl;

		};
	}
}