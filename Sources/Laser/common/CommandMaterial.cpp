#include <Laser/CommandMaterial.h>
#include <Laser/ShaderUniformBuffer.h>
#include <limits>

namespace Laser
{
	namespace Command
	{
		Material::Material()
			: mBlendSource( BLEND_ONE )
			, mBlendDest( BLEND_ZERO )
			, mDepthFunc( DEPTH_LESS )
			, mStencilFunc( STENCIL_ALWAYS )
			, mStencilRef( 0 )
			, mStencilMask( std::numeric_limits<unsigned int>::max() )
		{ }

	}
}