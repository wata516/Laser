#pragma once

#include <Laser/Window.h>
#include <TGUL/String.h>
#include <boost/shared_ptr.hpp>

namespace Laser
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow( );

	public:
		virtual bool Create( const TGUL::String &title, int x, int y, int width, int height );
		virtual void Close( );
		virtual bool Open( );
		virtual bool IsOpen( );
		virtual void Flip();
		virtual int GetWidth() const;
		virtual int GetHeight() const;

	private:
		class Impl;
		boost::shared_ptr< Impl > mImpl;
	};
}