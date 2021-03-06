﻿#pragma once

#include <bitset>

namespace TGUL
{
	class String;
}

namespace Laser
{
	class IVertexDeclare
	{
	public:
		enum TYPE
		{
			TYPE_P32,	//!<	POSITION float*4
			TYPE_C32,	//!<	COLOR float*4
			TYPE_T16,	//!<	TEXCOORD float*2
			TYPE_MAX
		};
		typedef std::bitset< IVertexDeclare::TYPE_MAX > VertexType;

	public:
		//!	@brief	１頂点のサイズを取得します
		virtual size_t GetSize() const = 0;
		virtual const VertexType &GetType( ) const = 0;
		
	};
}