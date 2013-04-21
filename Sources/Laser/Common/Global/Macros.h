#pragma once

namespace Laser
{
	namespace Macros
	{
		template<class T>
		struct Release{
			Release(T **ppObj ){
				if( *ppObj ) {
					*ppObj->Release();
				}
			}
		};
		
		template< size_t shift >
		struct BIT_LSHIFT {
			enum { value = 1 << shift };
		};
		
	}
}
#define BIT(shift) (1<<shift)
