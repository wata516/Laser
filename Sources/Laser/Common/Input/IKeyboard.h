#pragma once

namespace Laser
{
	namespace Input
	{
		class IKeyboard
		{
		public:
			enum KEY_TYPE {
				KEY_TYPE_ESCAPE,
				KEY_TYPE_SPACE,
				KEY_TYPE_MAX
			};

			virtual bool IsTrigger( KEY_TYPE key ) = 0;
			virtual bool IsPress( KEY_TYPE key ) = 0;
			virtual bool IsRelease( KEY_TYPE key ) = 0;
			virtual void Update( ) = 0;
		};
	}
}