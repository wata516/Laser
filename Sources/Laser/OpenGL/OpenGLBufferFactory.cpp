#include "OpenGLBufferFactory.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLShaderUniformBuffer.h"
#include "OpenGLTexture.h"

#include <TGUL/String.h>

#include <boost/assign.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace Laser
{
	bool CreateOpenGLVertexBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer )
	{
		*ppBuffer = new OpenGLVertexBuffer( );
		
		if( *ppBuffer == 0 ) {
			return false;
		}
		
		return true;
	}
	
	bool CreateOpenGLShaderUniformBuffer( const TGUL::String &name, Resource::Buffer **ppBuffer )
	{
		*ppBuffer = new OpenGLShaderUniformBuffer( );
		
		if( *ppBuffer == 0 ) {
			return false;
		}
		
		return true;
	}
	
	bool CreateOpenGLTexture( const TGUL::String &name, Resource::Buffer **ppBuffer )
	{
		*ppBuffer = new OpenGLTexture( );
		
		if( *ppBuffer == 0 ) {
			return false;
		}
		
		return true;
	}

	bool OpenGLBufferFactory::Create( const TGUL::String &name, Resource::Buffer **ppBuffer )
	{
		std::map< TGUL::String, boost::function< bool( const TGUL::String &, Resource::Buffer ** ) > > functions
		= boost::assign::map_list_of
		( "VertexBuffer", boost::bind( &CreateOpenGLVertexBuffer, name, ppBuffer ))		// VertexBuffer
		( "UniformBuffer", boost::bind( &CreateOpenGLShaderUniformBuffer, name, ppBuffer ))		// Uniform
		( "Texture", boost::bind( &CreateOpenGLTexture, name, ppBuffer ))		// Texture
		;
		*ppBuffer = 0;
		
		if( functions.find( name ) == functions.end() ) {
			return false;
		}
		
		if( functions[ name ]( name, ppBuffer ) == false ) {
			return false;
		}
		
		return true;
	}

}
