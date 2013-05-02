#pragma once

#include <boost/array.hpp>

namespace Laser
{
	namespace Command
	{
		class Material;
	};

	class Shader;
	class DrawStatus
	{
	public:
		struct DrawCommand {
			DrawCommand()
			: mCommandMaterial( 0 )
			{}

			Command::Material *mCommandMaterial;
		};
		
		DrawCommand &GetPrevCommand() { return mPrevCommand; }

	private:
		DrawCommand mPrevCommand;
	};
}
