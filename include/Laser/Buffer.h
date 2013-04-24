#pragma once

#include <Laser/Object.h>
#include <Laser/UUID.h>
#include <boost/function.hpp>
#include <boost/shared_array.hpp>

namespace TGUL
{
	class String;
}

namespace Laser
{
	namespace Resource
	{
		class Buffer : public Object
		{
		public:
			typedef boost::function< size_t( void *pAddress, size_t a, size_t n ) > WriteType;

			enum Status {
				STATUS_NONE,	//!< 作成されていない状態
				STATUS_READ,	//!< ファイル読み込み中状態
				STATUS_NORMAL,	//!< 通常状態
				STATUS_MAX

			};

			enum Parameter {
				PARAM_DEFAULT_READ = 20
			};
		public:
			Buffer( );

		public:
			static const UUID &GetUUID( ) { return UUIDS::IBUFFER; }
			virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		public:
			bool Execute( );

		public:
			virtual bool Allocate( size_t VertexSize, size_t ArrayNum ) { return false; }
			virtual bool Write( WriteType WriteFunction ) { return false; }

		protected:
			bool ReadASync( const TGUL::String &FileName, size_t ReadSize = PARAM_DEFAULT_READ );
			
			virtual bool ReadComplete( void *pBuffer, size_t BufferSize ) { return true; };

		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}
