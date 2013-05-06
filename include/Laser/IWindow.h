#pragma once

namespace TGUL
{
	class String;
}

namespace Laser
{
	class IWindow
	{
	public:
		virtual bool Create( const TGUL::String &title, int x, int y, int width, int height ) = 0;
		virtual void Close( ) = 0;
		virtual bool Open( ) = 0;
		virtual bool IsOpen( ) = 0;
		virtual void Render( ) const = 0;
		virtual void Flip() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
}