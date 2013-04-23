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
				STATUS_NORMAL	//!< 通常状態
			};
		public:
			Buffer( );

		public:
			static const UUID &GetUUID( ) { return UUIDS::IBUFFER; }
			virtual bool QueryInterface( const UUID &uuid, void **ppObject );

		public:
			bool Execute( );

		public:
			virtual bool Read( const TGUL::String &FileName ) = 0;
			virtual bool Allocate( size_t VertexSize, size_t ArrayNum ) { return false; }
			virtual bool Write( WriteType WriteFunction ) { return false; }
			
		protected:
			virtual bool ReadCompleteFunction( ) { return false; };
			
		private:
			class Impl;
			boost::shared_ptr< Impl > mImpl;
		};
	}
}
