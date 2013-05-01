#pragma once

#include <Laser/IBase.h>

namespace Laser
{
	class Shader;
	class VertexDeclare;

	namespace Command
	{
		class Shader : public IBase
		{
		public:
			static IDType< CLASS_ID_COMMAND_SHADER > ID;

		public:
			enum ShaderType
			{
				SHADER_TYPE_VERTEX,
				SHADER_TYPE_FRAGMENT,
				SHADER_TYPE_MAX
			};

		public:
			virtual ClassID GetClassID( ) const { return CLASS_ID_COMMAND_SHADER;}
			virtual Laser::Shader *GetShader( ShaderType type ) const = 0;
			virtual void SetShader( ShaderType type, Laser::Shader *pShader ) = 0;
			virtual bool Create( ) = 0;
			virtual bool IsAvailable( ) const = 0;
			virtual void BindVertexDeclare( const VertexDeclare &declare ) { mVertexDeclare = &declare; }

		private:
			const VertexDeclare *mVertexDeclare;

		};
	}
}
